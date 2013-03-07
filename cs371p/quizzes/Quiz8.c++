/*
CS371p: Quiz #8 (5 pts)
*/

/* -----------------------------------------------------------------------
1. In C++, what four methods constitute the orthodox canonical class form?
   [Sec. 5.6.1, Pg. 115]
   (2 pts)

default constructor
copy constructor
copy assignment operator
destructor
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (2 pts)

m1 f1 f2 m2 m5
m1 f1 m3 m5
*/

#include <iostream> // cout, endl

using namespace std;

struct A : exception {}; // extends exception
struct B : A         {}; // extends A

void f (bool b) {
    cout << "f1 ";
    if (b)
        throw B();
    cout << "f2 ";}

int main () {
    try {
        cout << "m1 ";
        f(false);
        cout << "m2 ";}
    catch (A& e) {
        cout << "m3 ";}
    catch (B& e) {
        cout << "m4 ";}
    cout << "m5 " << endl;

    try {
        cout << "m1 ";
        f(true);
        cout << "m2 ";}
    catch (A& e) {
        cout << "m3 ";}
    catch (B& e) {
        cout << "m4 ";}
    cout << "m5" << endl;

    return 0;}
