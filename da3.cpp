// da3.cpp
// Jenae Matson
// 2023-09-28
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates

#include <functional>
using std::function;

// didItThrow
// Runs a given function and sets a bool to whether or not it threw an exception
// May throw any exceptions that the given function ff throws
void didItThrow(const function<void()>& ff, bool& threw)
{
    try {
        ff();
        threw = false;
    }
    catch (...){
        threw = true;
        throw;
    }
}

// gcd
// Takes two ints and returns their greatest common divisor
// Does not throw
int gcd(int a, int b)
{
    // BASE CASE
    if (a == 0)
        return b;

    // RECURSIVE CASE 1
    if (a > b)
        gcd(b, a);

    // RECURSIVE CASE 2
    gcd(b % a, a);

}

