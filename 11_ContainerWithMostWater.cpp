#include "Header.h"

// 11. Container With Most Water
// Level - Medium
// 
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
// Notice that you may not slant the container.
// 
// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// 
// Example 2:
// Input: height = [1,1]
// Output: 1
// 
// Example 3:
// Input: height = [4,3,2,1,4]
// Output: 16
// 
// Example 4:
// Input: height = [1,2,1]
// Output: 2
// 
// 
// Constraints:
// 
// n = height.length
// 2 <= n <= 3 * 104
// 0 <= height[i] <= 3 * 104
// 

int maxArea(vector<int>& height) {
    int start = 0;
    int end = height.size()-1;

    int maxArea = 0;
    int h;
    int area;
    while (start < end)
    {
        h = min(height[start], height[end]);
        area = h * (end - start);
        maxArea = max(area, maxArea);

        if (height[start] <= height[end]) ++start;
        else --end;
    }
    return maxArea;
}

void test_maxArea()
{
    vector<vector<int>> tc = {{1,8,6,2,5,4,8,3,7}, {1,1}, {4,3,2,1,4}, {1,2,1}};
    vector<int> answers = {49, 1, 16, 2};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (maxArea(tc[i]) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
