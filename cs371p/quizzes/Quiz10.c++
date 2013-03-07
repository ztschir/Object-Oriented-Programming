/*
CS371p: Quiz #10 (5 pts)
*/

/* -----------------------------------------------------------------------
1. In C++, for the '>>' operator that is defined on 'int', what is
   the l-value / r-value nature of the return, the left argument, and
   the right argument?
   On istream?
   (2 pts)

r-value, r-value, r-value
l-value, l-value, l-value
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (2 pts)

3 3 true
3 2 false
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // 'bool' outputs as 'true' or 'false'

    {
    int  i = 2;
    int& j = ++i;
    cout << i          << " ";
    cout << j          << " ";
    cout << (&i == &j) << endl;
    }

    {
    int i = 2;
    int j = i++;
    cout << i          << " ";
    cout << j          << " ";
    cout << (&i == &j) << endl;
    }

    return 0;}
