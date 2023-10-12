// da3.hpp
// Jenae Matson
// 2023-09-28
//
// For CS 311 Fall 2023
// Header for Assignment 3 functions

#pragma once

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range

// lookup
// Finds the given index in the given LinkedList, and trows if index is out of range
template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head, std::size_t index)
{
    auto p = head;
    
    for (int i = 0; i < index; ++i) {
        if (p == nullptr)
            throw std::out_of_range("lookup: index out of range");
        p = p->_next;
    }
    if (p == nullptr)
        throw std::out_of_range("lookup: index out of range");
    return p->_data;
}

// Implementation in source file
void didItThrow(const std::function<void()>& ff, bool& threw);

// checkSorted
// Checks if the given range of values is in ascending order
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last)
{
    if (first == last)
        return true;
    auto prev = first;
    for (auto curr = ++first; curr != last; ++curr) {
        if (*curr < *prev)
            return false;
        prev = curr;
    }
    return true;
}


// Implementation in source file
int gcd(int a, int b);

