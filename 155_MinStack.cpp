#include "Header.h"

// 155. Min Stack
// Level - Easy
// 
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// 
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
// 
// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// Output
// [null,null,null,null,-3,null,0,-2]
// 
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
// 
// 
// Constraints:
// Methods pop, top and getMin operations will always be called on non-empty stacks.

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> S;
    MinStack() {
    }

    void push(int x) {
        if (S.empty())
        {
            S.push(pair<int,int>(x,x));
        }
        else
        {
            pair<int, int> top = S.top();
            top.first = x;
            top.second = min(top.second, x);
            S.push(top);
        }
    }

    void pop() {
        S.pop();
    }

    int top() {
        return S.top().first;
    }

    int getMin() {
        return S.top().second;
    }
};

void test_MinStack()
{
    vector<string> cmd = {"MinStack","push","push","push","getMin","pop","top","getMin"};
    vector<int> values = {0, -2, 0, -3, 0, 0, 0, 0};
    // Output
    vector<int> answers = {0, 0, 0, 0,-3, 0, 0,-2};

    MinStack st;
    for (unsigned i = 1; i < cmd.size(); ++i)
    {
        if (cmd[i] == "push")
        {
            st.push(values[i]);
        }
        else if (cmd[i] == "pop")
        {
            st.pop();
        }
        else if (cmd[i] == "top")
        {
            if (st.top() != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
        }
        else if (cmd[i] == "getMin")
        {
            if (st.getMin() != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
        }
    }
}
