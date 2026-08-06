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

#ifndef VKITHREADPOOL_VSY_THREADPOOL_H
#define VKITHREADPOOL_VSY_THREADPOOL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct vsy_Thread_Pool {
    void* impl; //!< \brief Pointer to implementation details.
} vsy_Thread_Pool;

typedef struct vsy_TaskID {
    int id;
} vsy_TaskID;

extern vsy_Thread_Pool
vsy_create_thread_pool(int numThreads);

/** \brief Enqueue a single task.
 *
 * @param threadPool The thread pool object on which to enqueue the task.
 * @param f Pointer to the function to be called.
 * @param p Pointer passed as argument to f.
 * @return
 */
extern vsy_TaskID
vsy_enqueue_task(vsy_Thread_Pool threadPool, void (*f)(void*), void* p);

/** \brief Wait for a task to finish.
 *
 * @param threadPool The thread pool object on which the task has been enqueued.
 * @param taskID The ID of the task.
 * @return 0 when the task is finished. 1 if the ID is invalid.
 */
extern int
vsy_wait_for_task(vsy_Thread_Pool threadPool, vsy_TaskID taskID);

extern void
vsy_destroy_thread_pool(vsy_Thread_Pool pool);

extern int
vsy_get_thread_id(void);

#ifdef __cplusplus
}
#endif

#endif // VKITHREADPOOL_VSY_THREADPOOL_H
