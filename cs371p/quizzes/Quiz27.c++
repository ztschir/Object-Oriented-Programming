/*
CS371p: Quiz #27 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Describe the difference in binding time between overloading and
   overriding.
   [Sec. 15.0, Pg. 287]
   (1 pt)

compile time vs. run time
*/

/* -----------------------------------------------------------------------
2. What two concepts characterize two broad categories of overloading?
   [Sec. 15.1, Pg. 289]
   (1 pt)

type signature and scope
*/

/* -----------------------------------------------------------------------
3. What is the output of the following?
   (2 pts)

A() A(A) A(A)
*/

#include <iostream> // cout, endl
#include <vector>   // vector

using namespace std;

struct A {
    A () {
        cout << "A() ";}

    A (const A&) {
        cout << "A(A) ";}};

int main () {
    vector<A> y(2);
    cout << endl;
    return 0;}
