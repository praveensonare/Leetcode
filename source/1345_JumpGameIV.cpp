#include "Utility.h"

// 1345. Jump Game IV
// Level - Hard
// Given an array of integers arr, you are initially positioned at the first index of the array.
// 
// In one step you can jump from index i to index:
// 
// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.
// Notice that you can not jump outside of the array at any time.
// 
//
// Example 1:
// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
//
// Example 2:
// Input: arr = [7]
// Output: 0
// Explanation: Start index is the last index. You don't need to jump.
//
// Example 3:
// Input: arr = [7,6,9,6,9,6,9,7]
// Output: 1
// Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
//
// Example 4:
// Input: arr = [6,1,9]
// Output: 2
//
// Example 5:
// Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
// Output: 3
// 
// Constraints:
// 1 <= arr.length <= 5 * 10^4
// -10^8 <= arr[i] <= 10^8


int minJumps(vector<int>& arr) {
    int len = arr.size();
    int target = len - 1;
    vector<bool>visited = vector<bool>(len, false);
    vector<int>stepsAtPos = vector<int>(len, INT_MAX);
    stepsAtPos[0] = 0;
    unordered_map<int, vector<int>> H;
    for (int i = 0; i < len; ++i) H[arr[i]].push_back(i);

    queue<pair<int,int>> Q; // pos, dist
    Q.push(pair<int,int>(0,0));
    visited[0] = true;
    pair<int,int> front;
    int step;
    while(!Q.empty())
    {
        front = Q.front();
        Q.pop();

        step = front.second + 1;
        if (front.first == target) return front.second;

        if (front.first > 0 && !visited[front.first - 1])
        {
            if (front.first - 1 == target) return step;
            Q.push(pair<int,int>(front.first - 1, step));
            visited[front.first - 1] = true;
        }

        if (front.first < target && !visited[front.first + 1])
        {
            if (front.first + 1 == target) return step;
            Q.push(pair<int,int>(front.first + 1, step));
            visited[front.first + 1] = true;
        }

        //cout << "count of " << arr[front.first] << " : " << H[arr[front.first]].size() << endl;
        for (int i = H[arr[front.first]].size() - 1; i >= 0; --i)
        {
            int p = H[arr[front.first]][i];

            if (p == target) return step;
            if (visited[p]) continue;

            visited[p] = true;
            Q.push(pair<int,int>(p, step));
        }
    }

    return INT_MAX;
}



void test_minJumps()
{
    VVI tc = {{100,-23,-23,404,100,23,23,23,3,404}, {7}, {7,6,9,6,9,6,9,7}, {6,1,9}, {11,22,7,7,7,7,7,7,7,22,13}};
    VI answers = {3,0,1,2,3};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (minJumps(tc[i]) != answers[i]) ERROR_LOG;
    }
}
