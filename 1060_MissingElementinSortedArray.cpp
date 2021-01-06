#include "Utility.h"

// 1060. Missing Element in Sorted Array
// Level - Medium
// 
// Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.
// 
// Example 1:
// Input: A = [4,7,9,10], K = 1
// Output: 5
// Explanation:
// The first missing number is 5.
// 
// Example 2:
// Input: A = [4,7,9,10], K = 3
// Output: 8
// Explanation:
// The missing numbers are [5,6,8,...], hence the third missing number is 8.
// 
// Example 3:
// Input: A = [1,2,4], K = 3
// Output: 6
// Explanation:
// The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
// 
// Note:
// 1 <= A.length <= 50000
// 1 <= A[i] <= 1e7
// 1 <= K <= 1e8


int missingElement(vector<int>& nums, int k) {
    int len = nums.size();
    int missed = 0;
    for (int i = 1; i <len; ++i)
    {
        k = k - (nums[i] - nums[i-1]) + 1 ;
        if (k <= 0)
        {
            return nums[i] + k - 1;
        }
    }
    return nums[len - 1] + k;
}

void test_missingElement()
{
    vector<pair<VI,int>> tc = {pair<VI,int>({4,7,9,10},1),
        pair<VI,int>({4,7,9,10},3),
        pair<VI,int>({1,2,4},3),
        pair<VI,int>({1,2,3},1)};

    VI answers = {5,8,6,4};

    for (unsigned i = 0; i > tc.size(); ++i)
    {
        if (missingElement(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
