#include "Utility.h"

// 251. Flatten 2D Vector
// Level - Medium
// Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.
// 
// Example:
// Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
// iterator.next(); // return 1
// iterator.next(); // return 2
// iterator.next(); // return 3
// iterator.hasNext(); // return true
// iterator.hasNext(); // return true
// iterator.next(); // return 4
// iterator.hasNext(); // return false
// 
// Notes:
// Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
// You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.
// 
// Follow up:
// As an added challenge, try to code it using only iterators in C++ or iterators in Java.

class Vector2D {
public:
    vector<int> V;
    int pos = -1;
    Vector2D(vector<vector<int>>& v) {
        pos = -1;
        V.clear();
        int size = 0;
        for (const auto& vec : v)
        {
            V.insert(V.end(), vec.begin(), vec.end());
        }

    }

    int next() {
        return V[++pos];
    }

    bool hasNext() {
        int next = pos + 1;
        return (next < V.size()) ? true : false;
    }
};

void test_Vector2D()                            // 251. Flatten 2D Vector
{
    vector<vector<int>> v = {{1,2}, {3}, {4}};
    Vector2D iterator(v);
    int i = 0;
    if (1 != iterator.next()) ERROR_LOG;
    ++i;
    if (2 != iterator.next()) ERROR_LOG;
    ++i;
    if (3 != iterator.next()) ERROR_LOG;
    ++i;
    if (!iterator.hasNext()) ERROR_LOG;
    ++i;
    if (!iterator.hasNext()) ERROR_LOG;
    ++i;
    if (4 != iterator.next()) ERROR_LOG;
    ++i;
    if (!iterator.hasNext()) ERROR_LOG;
}
