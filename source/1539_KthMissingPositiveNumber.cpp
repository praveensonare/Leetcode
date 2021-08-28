#include "Utility.h"

// 1539. Kth Missing Positive Number
// Level - Easy
// 
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Find the kth positive integer that is missing from this array.
// 
// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// 
// Example 2:
// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
// 
// Constraints:
// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length

#if 1
int findKthPositive(vector<int>& arr, int k) {
    if (arr.empty() || k < arr[0]) return k;

    int len = arr.size();
    int miss = arr[len-1] - len;
    int ret = 0;
    if (k > miss) return arr[len-1]+k-miss;
    else
    {
        miss = arr[0]-1;
        for (int idx = 1; idx < len; ++idx)
        {
            miss += arr[idx] - arr[idx-1] - 1;
            if (miss >= k)
            {
                int pos = miss - k + 1;
                ret = arr[idx] - pos;
                break;
            }


        }
    }
    return ret;
}
#else
// in non sorted array
int findKthPositive(vector<int>& arr, int k) {
    int len = arr.size();
    vector<int> myArr(len+k, INT_MAX);
    for (int idx = 0; idx < len; ++idx) myArr[idx] = (arr[idx] > 0) ? arr[idx] : INT_MAX;

    int val;
    len += k;
    for (int idx = 0; idx < len; ++idx)
    {
        val = abs(myArr[idx]) - 1;
        if (val < len && myArr[val] > 0) myArr[val] = -myArr[val];
    }

    int missed = 0;
    for (int idx = 0; idx < len; ++idx)
    {
        if (myArr[idx] > 0)
        {
            ++missed;
            if (missed == k) return idx + 1;
        }
    }

    return len + ( k - missed);
}
#endif

void test_findKthPositive()
{
    vector<pair<VI, int>> tc = {pair<VI,int>({1,2},1),
        pair<VI,int>({2,3,4,7,11}, 1),
        pair<VI,int>({2,3,4,7,11}, 2),
        pair<VI,int>({2,3,4,7,11}, 5),
        pair<VI,int>({1,2,3,4,5,6,7}, 1)};
    VI answers = { 3, 1, 5, 9, 8};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (findKthPositive(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
