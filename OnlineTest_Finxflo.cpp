#include <iostream>
#include <fstream>      // std::ifstream
#include "Header.h"
/*
Mountain Biking
At Finxflo, we always like to have some challenges and solve small fun problems, here is one that we enjoyed recently.

As an engineer, we can’t help but value efficiency, so naturally you want to cycle as long as possible and as fast as possible without having to cycle back up.

So you take a look at the map of the mountain and try to find the longest path down.

In digital form, the map will be in a .txt file and will look like the grid below.

4 4
4 8 7 3
2 5 9 3
6 3 2 5
4 4 1 6
The first line (4 4) indicates that this is a 4x4 map.

Each number represents the elevation of that area of the mountain.

From each position in the grid, you can go north, south, east, west - but only if the elevation of the area you are going into is less than the one you are in. (i.e. you can only cycle downhill).

You can start from anywhere on the map and look for a starting point with the longest possible path down as measured by the number of positions you visit.

If there are several paths of the same length, you want to take the steepest (i.e. the largest difference between your starting elevation and your ending elevation).

On this particular map, the longest path has a length of 5:

[ 9, 5, 3, 2, 1 ]

There is another path with a length of 5:

[ 8, 5, 3, 2, 1 ].

However, the tie is broken by the first path being steeper, dropping from 9 to 1 (a drop of 8), rather than just 8 to 1 (a drop of 7).

Your challenge is to write a program in Java to find the longest, and then steepest path on this map specified in the format above.

It’s max size is 1000x1000, and all the numbers on it are between 0 and 1500.

A sample testcase is available in the test folder. Feel free to add more maps and testcases.

Please fork our repository and share your solution in a private github repository where you will invite thomas@finxflo.com and yavuz@finxflo.com.

😎🚵 Good luck! 🚵😎
*/


class MountainBike {

private:
    vector<vector<int>> map;            // inputs
    vector<vector<vector<int>>> Hash;   // store downhill path so that recompute not required.
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<unsigned>> peaks;
    vector<vector<bool>> visited;

    bool checkValue(unsigned x, unsigned y, bool isLargest)
    {
        int newX, newY;
        for (unsigned dir = 0; dir < dx.size(); ++dir)
        {
            // checking adjecent 4 values. if all are less than this, then its a local peak.
            newX = x + dx[dir];
            newY = y + dy[dir];

            if (IsValidPosition(newY, newX) && (isLargest ? map[newY][newX] > map[y][x] : map[newY][newX] < map[y][x]))
            {
                return false;
            }
        }
        return true;
    }

    bool IsValidPosition(int y, int x)
    {
        return !(y < 0 || y >= (int)map.size() || x < 0 || x >= (int)map[0].size());
    }
public:

    MountainBike(string file) {
        // FIXME parse file and init map
        //map = new int[0][0];
        //ifstream f(file);
        //int H = 4, W = 4;
        //f >> H >> W;
#if 1
        map.push_back({4,8,7,3});
        map.push_back({2,5,9,3});
        map.push_back({6,3,2,5});
        map.push_back({4,4,1,6});
#else
        map.push_back({2,1,1,1});
        map.push_back({1,1,1,1});
        map.push_back({1,1,5,1});
        map.push_back({1,6,1,1});
#endif
        Hash = vector<vector<vector<int>>>(map.size(), vector<vector<int>>(map[0].size())); // init hash table
    }

    void findAllPeaks()
    {
        for (unsigned h = 0; h < map.size(); ++h)
        {
            for (unsigned w = 0; w < map[0].size(); ++w)
            {
                if (checkValue(w, h, true)) peaks.push_back({h,w});
            }
        }
    }

    vector<int> dfs(int y, int x)
    {
        if (!IsValidPosition(y, x))
            return {};

        if (!Hash[y][x].empty())
            return Hash[y][x];

        if (checkValue(y, x, false))
            return {map[y][x]};

        vector<int> bestDownPath;
        visited[y][x] = true;
        int newY, newX;

        // select remaining path with max slope that is smallest value at the end;
        for (unsigned dir = 0; dir < dx.size(); ++dir)
        {
            // checking adjecent 4 values. if all are less than this, then its a local peak.
            newY = y + dy[dir];
            newX = x + dx[dir];

            if (IsValidPosition(newY, newX) && !visited[newY][newX] && map[newY][newX] < map[y][x])
            {
                const vector<int>& downPath = dfs(newY, newX);

                if (!downPath.empty())
                {
                    if (downPath.size() > bestDownPath.size()) bestDownPath = downPath;
                    else if (downPath.size() == bestDownPath.size() && downPath[0] < bestDownPath[0]) bestDownPath = downPath;
                }
            }
        }

        visited[y][x] = false;
        bestDownPath.push_back(map[y][x]);
        Hash[y][x] = bestDownPath;
        return bestDownPath;
    }
    /**
     * Main logic
     *
     * @return path
     */
    vector<int> run() {

        if (map.empty()) return {}; // no path possible

        findAllPeaks();
        if (peaks.empty()) return {map[0][0]}; // all values are same, so max possible path length is 1.

        visited = vector<vector<bool>>(map.size(), vector<bool>(map[0].size(), false));

        vector<int> bestPath;
        unsigned pathLength = 0;

        for (auto v : peaks)
        {
            const vector<int>& path = dfs(v[0], v[1]);
            if (!path.empty())
            {
                pathLength = path.size();
                if (pathLength > bestPath.size()) bestPath = path;
                else if (pathLength == bestPath.size() && ((path[pathLength-1] - path[0]) > (bestPath[pathLength-1] - bestPath[0]))) bestPath = path;
            }
        }

        reverse(bestPath.begin(), bestPath.end());
        return bestPath;
    }
};

// OnlineTest_Finxflo.txt
void test_finxflo_MountainBiking()
{
    MountainBike M("OnlineTest_Finxflo.txt");
    vector<int> res = M.run();
    cout << "result is: ";
    for (auto n : res)
        cout << n << " ";
    cout << endl;
}
