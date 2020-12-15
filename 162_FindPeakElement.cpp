#include "Header.h"

// 162. Find Peak Element
// Level - Medium
// A peak element is an element that is strictly greater than its neighbors.
// 
// Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞.
// 
// Example 1:
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// 
// Example 2:
// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
// 
// Constraints:
// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.
// 
// Follow up: Could you implement a solution with logarithmic complexity?

int findPeakElement(vector<int>& nums) {
    int end = nums.size() - 1;
    int start = 0;
    int mid;

    while (start < end)
    {
        mid = start + (end - start)/2;
        if (nums[mid] > nums[mid+1]) end = mid;
        else start = mid + 1;
    }
    return start;
}

void test_findPeakElement()
{
    vector<vector<int>> tc = {{1,2,3,4}, {4,3,2,1}, {1,2,3,1}, {1,2,1,3,5,6,4}, {1,3,1,6,5,6,4}, {1,2,1,3,7,6,4}, {6}};

    vector<int> answers = {3, 0, 2, 5, 1, 4, 0};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (findPeakElement(tc[i]) != answers[i]) ERROR_LOG;
    }

}
