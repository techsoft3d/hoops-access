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
#ifndef ALLOCATOR_DEF
#define ALLOCATOR_DEF

#include "sam/vis/visutil.h"

template<typename T>
class VutAllocator {
  public:
    using value_type = T;

    VutAllocator() = default;

    template<typename U>
    constexpr VutAllocator(const VutAllocator<U>&) noexcept
    {
    }

    T*
    allocate(size_t n)
    {
        /* cppcheck-suppress CastIntegerToAddressAtReturn */
        return (T*)vut_mallocMem(n * sizeof(T));
    }

    void
    deallocate(T* p, size_t) noexcept
    {
        vut_MemoryFree(p);
    }
};

template<class T, class U>
bool
operator==(const VutAllocator<T>&, const VutAllocator<U>&)
{
    return true;
}

template<class T, class U>
bool
operator!=(const VutAllocator<T>&, const VutAllocator<U>&)
{
    return false;
}

#endif
