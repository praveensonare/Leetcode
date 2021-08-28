#include "Header.h"

// 46. Permutations
// Level - Medium
// 
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// 
// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// 
// Example 3:
// Input: nums = [1]
// Output: [[1]]
// 
// 
// Constraints:
// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

void myswap(int& a, int& b) {
    if (a == b) return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void help(vector<int>& nums, int pos, vector<int>& temp, vector<vector<int>>& result)
{
    int len = nums.size();
    if (pos >= len) return;

    if (pos == len - 1)
    {
        temp.push_back(nums[pos]);
        result.push_back(temp);
        temp.pop_back();
        return;
    }

    for (int i = pos; i < len; ++i)
    {
        myswap(nums[pos], nums[i]);
        temp.push_back(nums[pos]);
        help(nums, pos+1, temp, result);
        temp.pop_back();
        myswap(nums[pos], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;
    help(nums, 0, temp, result);
    return result;
}

void test_permute()
{
    VVI tc = {{1,2,3}, {0,1}, {1}};
    vector<VVI> answers = {{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2}},
                           {{0,1},{1,0}},
                           {{1}}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (permute(tc[i]) != answers[i]) ERROR_LOG;
    }
}
