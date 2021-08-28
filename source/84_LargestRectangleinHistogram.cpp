#include "Utility.h"

// 84. Largest Rectangle in Histogram
// Level - Hard
// 
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
// 
// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// 
// Example 2:
// Input: heights = [2,4]
// Output: 4
// 
// Constraints:
// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) return 0;

    stack<pair<int, int>> S; // pos, height
    heights.push_back(0);
    int len = heights.size();
    int max_area = 0;
    int area, pos;

    for (int i = 0; i < len; ++i)
    {
        area = 0;
        pos = i;
        while (!S.empty() && S.top().second >= heights[i])
        {
            area = S.top().second * (i - S.top().first);
            max_area = max(max_area, area);
            pos = S.top().first;
            S.pop();
        }

        S.push(pair<int,int>(pos, heights[i]));

    }
    return max_area;
}

void test_largestRectangleArea()
{
    VVI tc = {{2,1,5,6,2,3}, {2,4}};
    VI answers = {10, 4};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (largestRectangleArea(tc[i]) != answers[i]) ERROR_LOG;
    }
}
