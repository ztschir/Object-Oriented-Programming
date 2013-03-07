/*
CS371p: Quiz #19 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Which containers can back std::priority_queue<T>?
   (2 pts)

vector, deque
*/

/* -----------------------------------------------------------------------
2. There is a read-only and a read-write method, top(), in std::stack<T>.
   Are there both variants of front() and back() in std:queue<T>?
   If not, why not?
   Are there both variants of top() in std::priority_queue<T>?
   If not, why not?
   (2 pts)

yes
no, the read-write variant would potentially invalidate the heap invariant
*/
