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
#ifndef STDCONTAINERS_DEF
#define STDCONTAINERS_DEF

#include "sam/base/allocator.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <forward_list>
#include <queue>
#include <stack>
#include <string>
#include <string_view>

/* These are versions of allocating std containers that use the vut memory handling functions. */

namespace vsy {

    template<typename T>
    using vector = std::vector<T, VutAllocator<T>>;

    template<typename T>
    using list = std::list<T, VutAllocator<T>>;

    template<typename T>
    using deque = std::deque<T, VutAllocator<T>>;

    template<typename T>
    using forward_list = std::forward_list<T, VutAllocator<T>>;

    template<typename Key, typename Compare = std::less<Key>>
    using set = std::set<Key, Compare, VutAllocator<Key>>;

    template<typename Key, typename Compare = std::less<Key>>
    using multiset = std::multiset<Key, Compare, VutAllocator<Key>>;

    template<typename Key, typename T, typename Compare = std::less<Key>>
    using map = std::map<Key, T, Compare, VutAllocator<std::pair<const Key, T>>>;

    template<typename Key, typename T, typename Compare = std::less<Key>>
    using multimap = std::multimap<Key, T, Compare, VutAllocator<std::pair<const Key, T>>>;

    template<typename Key, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
    using unordered_multiset = std::unordered_multiset<Key, Hash, KeyEqual, VutAllocator<Key>>;

    template<typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
    using unordered_multimap = std::unordered_multimap<Key, T, Hash, KeyEqual, VutAllocator<std::pair<const Key, T>>>;

    using string = std::basic_string<char, std::char_traits<char>, VutAllocator<char>>;

    struct string_hash {
        std::size_t
        operator()(const string& str) const
        {
            return std::hash<std::string_view>{}(std::string_view(str.data(), str.size()));
        }
    };

    template<typename Key>
    using select_hash = std::conditional_t<std::is_same_v<Key, string>, string_hash, std::hash<Key>>;

    template<typename Key, typename Hash = select_hash<Key>, typename KeyEqual = std::equal_to<Key>>
    using unordered_set = std::unordered_set<Key, Hash, KeyEqual, VutAllocator<Key>>;

    template<typename Key, typename T, typename Hash = select_hash<Key>, typename KeyEqual = std::equal_to<Key>>
    using unordered_map = std::unordered_map<Key, T, Hash, KeyEqual, VutAllocator<std::pair<const Key, T>>>;

    template<typename T>
    string
    to_string(T value)
    {
        return string(std::to_string(value));
    }

    template<typename T, typename Container = vsy::deque<T>>
    using queue = std::queue<T, Container>;

    template<typename T, typename Container = vsy::deque<T>>
    using stack = std::stack<T, Container>;

    template<typename T, typename Container = vsy::vector<T>, typename Compare = std::less<typename Container::value_type>>
    using priority_queue = std::priority_queue<T, Container, Compare>;

    // Operator overloads for string concatenation with char*
    string inline
    operator+(const char* lhs, const string& rhs)
    {
        string result(lhs);
        result += rhs;
        return result;
    }

    string inline
    operator+(const string& lhs, const char* rhs)
    {
        string result(lhs);
        result += rhs;
        return result;
    }

} // namespace vsy

#endif
