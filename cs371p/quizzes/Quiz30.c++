/*
CS371p: Quiz #30 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What constructors/destructors does the following invoke?
   (4 pts)

ConwayCell() Cell()
FredkinCell() Cell()
~ConwayCell() FredkinCell()
~Cell() ~Cell() ~FredkinCell() ~FredkinCell()
*/

#include <iostream> // cout, endl

using namespace std;

int main () {
    {
    Cell x = new ConwayCell();
    cout << endl;

    Cell y = new FrekdinCell();
    cout << endl;

    x = y
    cout << endl;
    }
    cout << endl;

    return 0;}
