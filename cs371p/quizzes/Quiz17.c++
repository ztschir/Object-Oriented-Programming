/*
CS371p: Quiz #17 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Characterize S1 and S2 processes.
   [Object-Oriented Design]
   (2 pts)

S1: fast, unconscious, effortless, and inflexible
S2: slow, conscious,   effortful,  and flexible
*/

/* -----------------------------------------------------------------------
2. What is the output of the following blocks?
   Alternatively, the blocks might not compile.
   If a block doesn't compile, which line is illegal.
   (2 pts)
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int i = 2;
    typedef int* pointer;
          pointer  p = &i;
    const pointer& r = p;
    ++*r;
//  r = 0;                 // error: assignment of read-only reference ‘r’
    cout << i          << endl;
    cout << (&p == &r) << endl << endl;
    }

    {
    int i = 2;
    typedef const int* pointer_to_constant;
    pointer_to_constant  p = &i;
    pointer_to_constant& r = p;
//  ++*r;                  // error: increment of read-only location
    r = 0;
    cout << i          << endl;
    cout << (&p == &r) << endl;
    }

    return 0;}
