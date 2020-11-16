#include "Header.h"

// 1272. Remove Interval
// Level - Medium
// 
// Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.
// We remove the intersections between any interval in intervals and the interval toBeRemoved.
// Return a sorted list of intervals after all such removals.
// 
// Example 1:
// Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
// Output: [[0,1],[6,7]]
// 
// Example 2:
// Input: intervals = [[0,5]], toBeRemoved = [2,3]
// Output: [[0,2],[3,5]]
// 
// Example 3:
// Input: intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
// Output: [[-5,-4],[-3,-2],[4,5],[8,9]]
// 
// Constraints:
// 1 <= intervals.length <= 10^4
// -10^9 <= intervals[i][0] < intervals[i][1] <= 10^9


vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    int idx = 0;
    int len = intervals.size();

    vector<vector<int>> result;
    for (idx = 0; idx < len; ++idx)
    {
        if (toBeRemoved[0] <= intervals[idx][0])
        {
            break;
        }
        else if (toBeRemoved[0] < intervals[idx][1])
        {
            result.emplace_back(vector<int>({intervals[idx][0], toBeRemoved[0]}));
            break;
        }
        result.emplace_back(vector<int>(intervals[idx]));
    }
    
    for (; idx < len; ++idx)
    {
        if (intervals[idx][1] <= toBeRemoved[1]) continue;

        else if (intervals[idx][0] < toBeRemoved[1]) result.emplace_back(vector<int>({toBeRemoved[1], intervals[idx][1]}));
        else result.emplace_back(vector<int>(intervals[idx]));
        break;
    }
    
    ++idx;
    for ( ; idx < len; ++idx) result.emplace_back(vector<int>(intervals[idx]));

    return result;
}

void test_removeInterval()
{
    vector<pair<vector<vector<int>>, vector<int>>> tc = {pair<vector<vector<int>>, vector<int>>({{0,2},{3,4},{5,7}}, {1,6}),
                                                         pair<vector<vector<int>>, vector<int>>({{0,5}}, {2,3}),
                                                         pair<vector<vector<int>>, vector<int>>({{-5,-4},{-3,-2},{1,2},{3,5},{8,9}}, {-1,4})
                                                        };
    vector<vector<vector<int>>> answer = {{{0,1},{6,7}}, {{0,2},{3,5}}, {{-5,-4},{-3,-2},{4,5},{8,9}}};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (removeInterval(tc[i].first, tc[i].second) != answer[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
