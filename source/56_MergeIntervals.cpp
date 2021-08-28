#include "Header.h"

// 56. Merge Intervals
// Level - Medium
//
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
//
// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// Constraints:
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int len = intervals.size();
    if (len < 2) return intervals;

    sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){return v1[0] < v2[0];});
    vector<vector<int>> result(1, intervals[0]);

    for (int i = 1; i < len; ++i)
    {
        if (intervals[i][0] <= result.back()[1])
        {
            result.back()[1] = result.back()[1] > intervals[i][1] ? result.back()[1] : intervals[i][1];
        }
        else
            result.emplace_back(intervals[i]);
    }
    return result;
}

void test_merge()
{
    vector<vector<vector<int>>> tc = { {{1,3}, {2,6}, {8,10}, {15,18}},
                                       {{1,4}, {4,5}}};
    vector<vector<vector<int>>> answer = {{{1,6}, {8,10}, {15,18}}, {{1,5}}};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (merge(tc[i]) != answer[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
