#include "Utility.h"

// 312. Burst Balloons
// Level - Hard
// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
// 
// Find the maximum coins you can collect by bursting the balloons wisely.
// 
// Note:
// You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
// 
// Example:
// Input: [3,1,5,8]
// Output: 167
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
// 

int solve(vector<int>nums, int start, int end, vector<vector<int>>& memo)
{
    if (start+1 == end) return 0;
    if (memo[start][end] > 0) return memo[start][end];

    int ans = 0;
    int prod;
    for (int i = start + 1; i < end; ++i)
    {
        prod = nums[start] * nums[i] * nums[end] + solve(nums, start, i, memo) + solve(nums, i, end, memo);
        ans = max(ans, prod);
    }
    memo[start][end] = ans;
    return memo[start][end];
}

int maxCoins(vector<int>& nums) {
    int len = nums.size() + 2;
    vector<int> newNums(len);
    for (int i = 0; i < len-2; ++i) newNums[i+1] = nums[i];
    newNums[0] = newNums[len-1] = 1;

    vector<vector<int>> memo(len, vector<int>(len,0));
    return solve(newNums, 0, len-1, memo);
}

void test_maxCoins()
{
    vector<vector<int>> tc = {{3,1,5,8}};
    vector<int> answers = {167};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (maxCoins(tc[i]) != answers[i]) ERROR_LOG;
    }
}
