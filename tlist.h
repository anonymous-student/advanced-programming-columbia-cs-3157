#ifndef __TLIST_H__
#define __TLIST_H__


#include <string>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;


// These template declarations are needed for the friend declaration.
template <typename T>
class TList;
template <typename T>
ostream& operator<<(ostream& os, const TList<T>& rhs);
template <typename T>
TList<T> operator+(const TList<T>& lhs, const TList<T>& rhs);


template <typename T>
class TList {

    public:

	// compiler-generated basic 4 are just fine for us.

	// test if it's an empty list
	int isEmpty() const { return l.empty(); }

	// return the number of nodes in the list
	int size() const { return l.size(); }

	// add a T object to the front of the list
	void addFront(const T& t) { l.push_front(t); }

	// Pop a T object from the front of the list.
	// The result of popping from an empty list is undefined.
	T popFront() { 
	    T t(l.front()); 
	    l.pop_front();
	    return t;
	}

	// reverse the list
	void reverse() { ::reverse(l.begin(), l.end()); }

	// operator+=
	// The result of "tl += tl" is undefined.
	TList<T>& operator+=(const TList<T>& rhs);

	// operator+
	// implemented using op+=(), thus doesn't need to be a friend.
	// 
	// Declared as friend anyway to demonstrate how to do it.
	// Note that '::' and '()' are needed to make it compile under
	// g++ 4.6.3.  The operator<< does not require either.
	//
        friend TList<T>
            (::operator+<T>)(const TList<T>& lhs, const TList<T>& rhs);

	// put-to operator
	friend ostream& operator<< <T>(ostream& os, const TList<T>& rhs);

	// operator[]: 
	// The result of accessing beyond the last element is undefined.
	T& operator[](int idx);

	// operator[] const:
	// The result of accessing beyond the last element is undefined.
	const T& operator[](int idx) const { 
	    return ((TList&)*this)[idx];
	}

    private:

	list<T> l;
};

template <typename T>
TList<T>& TList<T>::operator+=(const TList<T>& rhs)
{
    for (auto i = rhs.l.begin(); i != rhs.l.end(); ++i)
	l.push_back(*i);
    return *this;
}

template <typename T>
TList<T> operator+(const TList<T>& lhs, const TList<T>& rhs)
{
    TList<T> t(lhs);
    t += rhs;
    return t;
}

template <typename T>
ostream& operator<<(ostream& os, const TList<T>& rhs)
{
    os << "{ ";
    for (auto i = rhs.l.begin(); i != rhs.l.end(); ++i)
	os << *i << " ";
    os << "}";
    return os;
}

template <typename T>
T& TList<T>::operator[](int idx)
{
    auto iter = l.begin();
    for (int i = 0; i < idx; i++)
	++iter;
    return *iter;
}

#endif
