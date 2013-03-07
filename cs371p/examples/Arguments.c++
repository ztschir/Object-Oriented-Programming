// -------------
// Arguments.c++
// -------------

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl

void f (int v, int* p, int& r) {
    ++v;
    ++(*p);
    ++r;}

void g (std::string v, std::string* p, std::string& r) {
    ++v[1];
    ++(*p)[1];
    ++r[1];}

void h (int b[]) {
    ++b;
    ++b[0];}

int main () {
    using namespace std;
    cout << "Arguments.c++" << endl;

    {
    int i = 2;
    int j = 2;
    int k = 2;
    f(i, &j, k);
    assert(i == 2);
    assert(j == 3);
    assert(k == 3);
    }

    {
    string s = "abc";
    string t = "abc";
    string u = "abc";
    g(s, &t, u);
    assert(s == "abc");
    assert(t == "acc");
    assert(u == "acc");
    }

    {
    int a[] = {2, 3, 4};
    h(a);
    assert(a[0] == 2);
    assert(a[1] == 4);
    assert(a[2] == 4);
    }

    cout << "Done." << endl;
    return 0;}
