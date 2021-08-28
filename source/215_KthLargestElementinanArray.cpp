#include "Utility.h"

// 215. Kth Largest Element in an Array
// Level - Medium
// 
// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
// 
// Example 1:
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// 
// Example 2:
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// 
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.
// 

class mycomp
{
    public:
        mycomp(){}
        bool operator() (int& a, int& b) { return a > b;}
};

int findKthLargest(vector<int>& nums, int k) {

    priority_queue<int, vector<int>, mycomp> Q;
    int top;
    for (auto n : nums)
    {
        if (Q.size() < (unsigned)k) Q.push(n);
        else
        {
            top = Q.top();
            if (n > top)
            {
                Q.pop();
                Q.push(n);
            }
        }
    }

    return Q.top();
}

void test_findKthLargest()
{
    vector<pair<vector<int>, int>> tc = {pair<vector<int>, int>({3,2,1,5,6,4}, 2),
                                         pair<vector<int>, int>({3,2,3,1,2,4,5,5,6}, 4)};
    vector<int> answers = {5, 4};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (findKthLargest(tc[i].first, tc[i].second) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
