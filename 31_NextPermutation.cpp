#include "Header.h"

// 31. Next Permutation
// Level - Medium
// 
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
// The replacement must be in place and use only constant extra memory.
// 
// Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]
// 
// Example 2:
// Input: nums = [3,2,1]
// Output: [1,2,3]
// 
// Example 3:
// Input: nums = [1,1,5]
// Output: [1,5,1]
// 
// Example 4:
// Input: nums = [1]
// Output: [1]
// 
// 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100


void nextPermutation(vector<int>& nums) {
    //std::next_permutation(nums.begin(), nums.end());
    auto getGreater = [](const vector<int>& nums, int val)
    {
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (val < nums[i]) return i;
        }
        return 0;
    };
    int idx = 0;
    for (int i = nums.size() - 1; i > 0; --i)
    {
        if (nums[i-1] < nums[i])
        {
            idx = getGreater(nums, nums[i-1]);
            nums[idx] = nums[i-1] ^ nums[idx];
            nums[i-1] = nums[i-1] ^ nums[idx];
            nums[idx] = nums[i-1] ^ nums[idx];

            sort(nums.begin()+i, nums.end());
            return;
        }
    }

    reverse(nums.begin(), nums.end());
}

void test_nextPermutation()
{
    vector<vector<int>> tc = {{1,2,3}, {3,2,1}, {1,1,5}, {1}};
    vector<vector<int>> answers = {{1,3,2}, {1,2,3}, {1,5,1}, {1}};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        nextPermutation(tc[i]);
        if (tc[i] != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
