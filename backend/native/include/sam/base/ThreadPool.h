/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
//
// Created by Michel Lesoinne on 7/2/18.
//

#ifndef VKITHREADPOOL_THREADPOOL_H
#define VKITHREADPOOL_THREADPOOL_H

#include "sam/base/stdcontainers.h"
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
namespace VKI {

    class ThreadPool {
      public:
        ThreadPool(size_t num_threads);

        /** \brief Change the number of threads in the pool. */
        void
        resize(int num_threads);

        unsigned int
        numThreads() const
        {
            return static_cast<unsigned int>(workers.size());
        }

        template<class F, class... Args>
        auto
        enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

        ~ThreadPool();

      private:
        // need to keep track of threads so we can join them
        vsy::vector<std::thread> workers;
        // the task queue
        vsy::queue<std::function<void()>> tasks;

        // synchronization
        std::mutex queue_mutex;
        std::condition_variable condition;
        bool stop;
    };

    int&
    getMyThreadID();

    // the constructor just launches some amount of workers
    inline ThreadPool::ThreadPool(size_t threads): stop(false)
    {
        for (size_t i = 0; i < threads; ++i)
            workers.emplace_back([this, i]() -> void {
                getMyThreadID() = static_cast<int>(i);
                for (;;) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock, [this] {
                            return this->stop || !this->tasks.empty();
                        });
                        if (this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }

                    task();
                }
            });
    }

    // add new work item to the pool
    template<class F, class... Args>
    auto
    ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif
        using return_type = typename std::result_of<F(Args...)>::type;
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
        auto task =
        std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            // don't allow enqueueing after stopping the pool
            if (stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            tasks.emplace([task]() {
                (*task)();
            });
        }
        condition.notify_one();
        return res;
    }

    // the destructor joins all threads
    inline ThreadPool::~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread& worker: workers)
            worker.join();
    }

    /** \brief A Thread Pool that distinguishes tasks that rely on the use
     * of advanced numerical hardware or not.
     *
     * \details Tasks that involve matrix multiplication operations
     * are an example of numerical tasks, while tasks that do re-ordering or
     * gather/scatter operations are not. Tasks doing assembly probably fall better
     * under the non-numerical model as they do not rely on heavy vector operations
     * such as vector fused multiply-add.
     */
    class AdvancedThreadPool {
      public:
        explicit AdvancedThreadPool(size_t numThreads);
        template<class F, class... Args>
        auto
        enqueueNumerical(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;
        template<class F, class... Args>
        auto
        enqueueAdmin(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

      private:
        ThreadPool numericalPool;
        ThreadPool adminPool;
    };

    inline AdvancedThreadPool::AdvancedThreadPool(size_t numThreads): numericalPool(numThreads), adminPool(numThreads) {}

    template<class F, class... Args>
    auto
    AdvancedThreadPool::enqueueNumerical(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
        return numericalPool.enqueue(std::forward<F>(f), std::forward<Args>(args)...);
    }

    template<class F, class... Args>
    auto
    AdvancedThreadPool::enqueueAdmin(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
        return adminPool.enqueue(std::forward<F>(f), std::forward<Args>(args)...);
    }

} // namespace VKI
#endif // VKITHREADPOOL_THREADPOOL_H
