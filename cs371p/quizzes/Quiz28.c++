/*
CS371p: Quiz #28 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Name the two mechanisms through which interfaces can be separated.
   [The Interface Segregation Principle]
   (2 pts)

delegation
multiple inheritance
*/

/* -----------------------------------------------------------------------
2. Define operators !=, <=, >, and >= in terms of == and <.
   (2 pts)
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

struct A {};

template <typename T>
bool operator == (const T& lhs, const T& rhs) {
    return true;}

template <typename T>
bool operator < (const T& lhs, const T& rhs) {
    return false;}

template <typename T>
bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

int main () {
    A x;
    A y;

    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));

    cout << "Done." << endl;
    return 0;}
