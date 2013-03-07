/*
CS371p: Quiz #26 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following?
   (4 pts) 13 / 47

A()
A() =(A)
=(A)
~A() ~A()
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    A () {
        cout << "A() ";}

    A (const A&) {
        cout << "A(A) ";}

    ~A () {
        cout << "~A() ";}

    A& operator = (const A&) {
        cout << "=(A) ";
        return *this;}};

struct B {
    A x;

    B () :
        x () {}

    B (const B& rhs) {
        x = rhs.x;}

    };

int main () {
    {
    B y;
    cout << endl;

    B z = y;
    cout << endl;

    z = y;
    cout << endl;
    }
    cout << endl;

    return 0;}
