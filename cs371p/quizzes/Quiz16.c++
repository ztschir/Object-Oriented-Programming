/*
CS371p: Quiz #16 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What distinguishes refinement overriding from replacement overriding?
   [Sec. 10.7, Pg. 217]
   (2 pts)

the overriding method replaces the base version
the overriding method runs in a addition to the base version
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (2 pts)

A()
A(A) ~A()
A() ~A()
~A()
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    A () {                     // default constructor
        cout << "A() ";}

    A (const A&) {             // copy constructor
        cout << "A(A) ";}

    ~A () {                    // destructor
        cout << "~A() ";}

    A& operator = (const A&) { // copy assignment operator
        cout << "=(A) ";
        return *this;}};

void f (A)
    {}

int main () {
    {
    A v;
    cout << endl;

    f(v);
    cout << endl;

    f(A());
    cout << endl;
    }
    cout << endl;

    return 0;}
