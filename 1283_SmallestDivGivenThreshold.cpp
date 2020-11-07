#include "Header.h"
#if 0
Find the Smallest Divisor Given a Threshold
Level - Medium

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
It is guaranteed that there will be an answer.

Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

Example 2:
Input: nums = [2,3,5,7,11], threshold = 11
Output: 3

Example 3:
Input: nums = [19], threshold = 5
Output: 4
#endif
auto getMod = [](int num, int den) {
    int mod;
    if (num % den == 0) return num / den;
    else return 1 + (num / den);
};

int GetSumOfDiv(vector<int>& nums, int den)
{
    int res = 0;
    for (auto n : nums)
    {
        res += getMod(n, den);
    }
    return res;
}

int GetMaxFromVector(vector<int> nums)
{
    int _max = 0;
    for (auto n : nums)
        _max = (n > _max) ? n : _max;
    return _max;
}
int smallestDivisor(vector<int>& nums, int threshold)
{
    int start = 1;
    int end = GetMaxFromVector(nums);
    int mid;

    int ans;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        ans = GetSumOfDiv(nums, mid);
        if (ans <= threshold) end = mid;
        else if (ans > threshold) start = mid + 1;
    }
    return start;
}
