/*
CS371p: Quiz #25 (5 pts)
*/

/* -----------------------------------------------------------------------
1. A piece of software that fulfills its requirements and yet exhibits any
   or all of the following three traits has a bad design.
   List any two.
   [The Dependency Inversion Principle]
   (2 pts)

1. It is hard to change because every change affects too many other parts
   of the system.
   (Rigidity)

2. When you make a change, unexpected parts of the system break.
   (Fragility)

3. It is hard to reuse in another application because it cannot be
   disentangled from the current application.
   (Immobility)
*/

/* -----------------------------------------------------------------------
2. What is the output of the call to f()?
   Alternatively, it might not compile.
   If a line doesn't compile, why not?
   There is no syntax error.
   (2 pts)

2
*/

#include <iostream> // cout, endl

using namespace std;

template <typename T>
void f (const T&);

template <typename T>
class A {
    friend void f<T>(const T&);

    private:
        T _v;

    public:
        A (const T& v) :
            _v (v)
        {}};

template <typename T>
void f (const T& v) {
    A<T> x(v);
    cout << x._v << endl;}

int main () {
    f(2);
    return 0;}
