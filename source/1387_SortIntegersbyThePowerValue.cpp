#include "Header.h"

// 1387. Sort Integers by The Power Value
// Level - Medium
// f an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
// 
// if x is even then x = x / 2
// if x is odd then x = 3 * x + 1
// For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
// Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.
// Return the k-th integer in the range [lo, hi] sorted by the power value.
// Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.
// 
// 
// 
// Example 1:
// Input: lo = 12, hi = 15, k = 2
// Output: 13
// Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
// The power of 13 is 9
// The power of 14 is 17
// The power of 15 is 17
// The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
// Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
// 
// Example 2:
// Input: lo = 1, hi = 1, k = 1
// Output: 1
// 
// Example 3:
// Input: lo = 7, hi = 11, k = 4
// Output: 7
// Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
// The interval sorted by power is [8, 10, 11, 7, 9].
// The fourth number in the sorted array is 7.
// 
// Example 4:
// Input: lo = 10, hi = 20, k = 5
// Output: 13
// 
// Example 5:
// Input: lo = 1, hi = 1000, k = 777
// Output: 570
// 
// Constraints:
// 1 <= lo <= hi <= 1000
// 1 <= k <= hi - lo + 1
// 

unordered_map<int,int> memo;
int GetPower(int n, int p)
{
    if (memo.find(n) != memo.end()) return memo[n];
    if (n <= 1) return 0;
    return  memo[n] = 1 + GetPower((n % 2 == 0) ? n / 2 : 3 * n + 1, 1+p);
}

int getKth(int lo, int hi, int k) {
    vector<vector<int>> nums;
    for (int i = lo; i <= hi; ++i)
    {
        nums.push_back({i, GetPower(i, 0)});
    }

    sort(nums.begin(), nums.end(),[](vector<int>& v1, vector<int>& v2){
            if (v1[1] == v2[1]) return v1[0] < v2[0];
            else return v1[1] < v2[1];
            });

    return nums[k-1][0];
}

void test_getKth()
{
    VVI tc = {VI{3,4,1}, VI{12,15,2}, {1,1,1}, {7,11,4}, {10,20,5}, {1,1000,777}};
    VI answers = {4,13,1,7,13,570};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (getKth(tc[i][0], tc[i][1], tc[i][2]) != answers[i]) ERROR_LOG;
    }
}
