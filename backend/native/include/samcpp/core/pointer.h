#pragma once

#include <memory>
#include <type_traits>

namespace cae::core {

struct nop {
    template <typename T>
    void operator()(T const &) const noexcept
    {
    }
};

template <class T>
class Pointer : public std::conditional<std::is_arithmetic_v<T>, std::unique_ptr<T, nop>, std::unique_ptr<T>>::type {};

template <class T, class... Args>
Pointer<T> createPointer(Args &&...args)
{
    Pointer<T> pointer;
    pointer.reset(new T(std::forward<Args>(args)...));
    return pointer;
}

} // namespace cae::core
