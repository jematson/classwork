// fsarray.hpp
// Jenae Matson
// 2023-9-20
// Class template for a fairly smart array

#pragma once

#include <cstddef>	// for size_t
#include <algorithm>	// for std algorithms (fill, copy, etc.)
#include <cassert>	// for assert
#include <utility>	// for swap

// *************************
// ***** Class FSArray *****
// *************************
// Class Invariants: size >= 0

template <typename T>
class FSArray {
public:

// ***** FSArray: Types *****
	using value_type = T;
	using size_type = std::size_t;


// ***** FSArray : ctors, dtor, op= *****
	// Default ctor
	// Create an FSArray of size 8
	FSArray() 
		:_size(8), _arrayptr(new value_type[8])
	{}

	// Dtor
	~FSArray() {
		delete[] _arrayptr;
	}

	// Copy ctor
	FSArray(const FSArray& other)
		: _size(other._size), _arrayptr(new value_type[other._size])
	{
		std::copy(other.begin(), other.end(), this->begin());
	}

	// Copy assignment operator
	FSArray & operator=(const FSArray& rhs)
	{
		FSArray copy_of_rhs(rhs);
		mswap(copy_of_rhs);
		return *this;
	}

	// Move ctor
	FSArray(FSArray&& other) noexcept
		:_size(other._size), _arrayptr(other._arrayptr)
	{
		other._size = 0;
		other._arrayptr = nullptr;
	}
	
	// Move assignment operator
	FSArray & operator=(FSArray && rhs) noexcept {
		mswap(rhs);
		return *this;
	}


	// 1-parameter ctor
	// Sets size to size given
	explicit FSArray(size_type size)
		: _size(size), _arrayptr(new value_type[_size])
	{}

	// 2-parameter ctor
	// Sets size to size given and fills the FSArray with the given item
	FSArray(size_type size, T item)
		:_size(size), _arrayptr(new value_type[_size])
	{
		std::fill(this->begin(), this->end(), item);
	}


// ***** FSArray : Member functions and operator [] *****
	
	// size()
	// Returns size of the FSArray
	size_t size() const {
		return _size;
	}

	// begin()
	// Returns pointer to first item in FSArray
	value_type* begin() {
		return &_arrayptr[0];
	}

	// begin() const
	// Const version of begin()
	const value_type* begin() const {
		return &_arrayptr[0];
	}

	// end()
	// Returns pointer to item after last item in FSArray
	value_type* end() {
		return &_arrayptr[_size];
	}

	// end() const
	// Const version of end()
	const value_type* end() const {
		return &_arrayptr[_size];
	}

	// op []
	// Returns address of item at index given
	// Preconditions: index is within the range of the FSArray
	value_type& operator[](size_type index) {
		assert(index >= 0 && index <= _size - 1);

		return _arrayptr[index];
	}

	// op [] const
	// Const version of op []
	// Preconditions: index is within the range of the FSArray
	const value_type& operator[](size_type index) const {
		assert(index >= 0 && index <= _size - 1);

		return _arrayptr[index];
	}

// ***** FSArray : Member variables *****
private:
	// Stores the size of the FSArray
	size_type _size;

	// Pointer to the first item in the FSArray
	value_type* _arrayptr;

// ***** FSArray: Private member function *****

	// mswap
	// Swaps the current objects data members with those of the given FSArray
	// Function taken from class slides 9/13 by Glenn Chappell
	void mswap(FSArray& other) noexcept {
		std::swap(_size, other._size);
		std::swap(_arrayptr, other._arrayptr);
	}

};	// End of class FSArray


// ***** FSArray: Global operators *****

// ==
// Tests if the given FSArrays have the same size and equal corresponding items.
// Preconditions: value types of FSArrays given must be the same
template<typename T>
bool operator==(const FSArray<T>& a, const FSArray<T>& b) {
	return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin(), b.end());
}

// !=
// Tests if the given FSArrays are not equal
// Preconditions: value types of FSArrays given must be the same
template<typename T>
bool operator!=(const FSArray<T>& a, const FSArray<T>& b) {
	return !(a == b);
}

// < 
// Tests if the first FSArray is less than the second FSArray
// An FSArray is less than another if its first non-equal corresponding item is less than the other's.
// If all items are equal, then the FSArray is less than the other if its size is smaller.
// Preconditions: value types of FSArrays given must be the same
template<typename T>
bool operator<(const FSArray<T>& a, const FSArray<T>& b) {
	int length;
	if (a.size() > b.size())
		length = b.size();
	else
		length = a.size();

	for (int i = 0; i < length; ++i) {
		if (a[i] < b[i] || b[i] < a[i])
			return a[i] < b[i];	
	}
	return a.size() < b.size();
}

// >
// Tests if the first FSArray is greater than the second
// Preconditions: value types of FSArrays given must be the same
template<typename T>
bool operator>(const FSArray<T>& a, const FSArray<T>& b) {
	return b < a;
}

// >=
// Tests if the first FSArray is greater than or equal to the second
// Preconditions: value types of FSArrays given must be the same
template<typename T>
bool operator>=(const FSArray<T>& a, const FSArray<T>& b) {
	return !(a < b);
}


// <=
// Tests if the first FSArray is less than or equal to the second
// Preconditions: value types of FSArrays given must be the same
template<typename T>
bool operator<=(const FSArray<T>& a, const FSArray<T>& b) {
	return !(b < a); 
}
