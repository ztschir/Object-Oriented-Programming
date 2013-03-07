/*
CS371p: Quiz #22 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What mechanism can be used in a fashion that is very nearly equivalent
   to multiple inheritance, but avoids many of the semantic problems.
   [Sec. 13.5, Pg. 271]
   (1 pt)

inner classes
*/

/* -----------------------------------------------------------------------
2. Describe something that can be done with inheritance that can't be done
   with composition.
   [Sec. 14.2.3, pg. 282]
   (1 pt)

substitution
*/

/* -----------------------------------------------------------------------
3. What is the output of the following program?
   Alternatively, the line might not compile.
   If a line doesn't compile, which line is illegal.
   (2 pts)

true
false
*/

#include <iostream> // cout, endl

template <typename T>
struct A {
    static int si;};

template <typename T>
int A<T>::si;

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    cout << ( A<int>::si ==  A<double>::si) << endl;
    cout << (&A<int>::si == &A<double>::si) << endl;

    return 0;}
