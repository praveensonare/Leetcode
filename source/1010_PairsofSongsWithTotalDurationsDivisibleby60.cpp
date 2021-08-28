#include "Header.h"

// 1010. Pairs of Songs With Total Durations Divisible by 60
// Level - Medium
// 
// You are given a list of songs where the ith song has a duration of time[i] seconds.
// Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
// 
// Example 1:
// Input: time = [30,20,150,100,40]
// Output: 3
// Explanation: Three pairs have a total duration divisible by 60:
// (time[0] = 30, time[2] = 150): total duration 180
// (time[1] = 20, time[3] = 100): total duration 120
// (time[1] = 20, time[4] = 40): total duration 60
// 
// Example 2:
// Input: time = [60,60,60]
// Output: 3
// Explanation: All three pairs have a total duration of 120, which is divisible by 60.
// 
// Constraints:
// 1 <= time.length <= 6 * 104
// 1 <= time[i] <= 500

int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> rem(60,0);
    for (auto& t : time) rem[t%60]++;

    int count = (rem[0] * (rem[0] - 1)) / 2;
    int start = 1;
    int end = 59;
    while (start < end)
    {
        count += (rem[start] * rem[end]);
        ++start;
        --end;
    }

    count += (rem[30] * (rem[30] - 1)) / 2;
    return count;
}

void test_numPairsDivisibleBy60()
{
    vector<vector<int>> tc = {{418,204,77,278,239,457,284,263,372,279,476,416,360,18},
                              {30,20,150,100,40}};
    vector<int> answers = {1,3};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (numPairsDivisibleBy60(tc[i]) != answers[i]) ERROR_LOG;
    }
}
