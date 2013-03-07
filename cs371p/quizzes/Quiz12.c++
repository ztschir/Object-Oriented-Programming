/*
CS371p: Quiz #12 (5 pts)
*/

/* -----------------------------------------------------------------------
1. In the paper "Totally Awesome Software" how did Beck at Chrysler
   eliminate the need for exhaustive specifications and a large 'quality
   assurance' team?
   (2 pts)

writing tests before writing code
*/

/* -----------------------------------------------------------------------
2. In the following two calls of the function sum(),
   what are the values of I and T?
   (2 pts)

int*, int
set<int>::iterator, int
*/

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <set>      // set

using namespace std;

template <typename I, typename T>
T sum (I b, I e, T v) {
    while (b != e) {
        v += *b;
        ++b;}
    return v;}

int main () {
    int a[] = {2, 3, 4};
    assert(sum(a, a + 3, 0) == 9);

    set<int> x(a, a + 3);
    assert(sum(x.begin(), x.end(), 0) == 9);

    cout << "Done." << endl;
    return 0;}
