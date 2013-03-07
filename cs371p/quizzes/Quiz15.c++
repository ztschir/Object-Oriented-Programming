/*
CS371p: Quiz #15 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

A()
A(A) A(A)
A(A)
A(A) A(A) ~A()
~A() ~A() ~A() ~A() ~A()
*/

#include <iostream> // cout, endl
#include <vector>   // vector

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

int main () {
    {
    A v;
    cout << endl;

    vector<A> x(2, v);
    cout << endl;

    vector<A> y(1, v);
    cout << endl;

    y = x;
    cout << endl;
    }
    cout << endl;

    return 0;}
