#include "Header.h"

// 973. K Closest Points to Origin
// Level - Medium
// 
// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// 
// (Here, the distance between two points on a plane is the Euclidean distance.)
// 
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
// 
// 
// Example 1:
// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
// 
// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)
// 
// 
// Note:
// 
// 1 <= K <= points.length <= 10000
// -10000 < points[i][0] < 10000
// -10000 < points[i][1] < 10000


#define PAIR pair<int, vector<int>>
class mycomp
{
public:
    mycomp(){}
    bool operator() (PAIR& a, PAIR& b) { return a.first < b.first; }
};

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue <PAIR, vector<PAIR>, mycomp> PQ;

        PAIR top;
        int dist;
        for (auto p : points)
        {
            dist = p[0]*p[0] + p[1]*p[1];
            if (PQ.size() < K)
            {
                PQ.push(PAIR(dist, p));
            }
            else
            {
                top = PQ.top();
                if (dist < top.first)
                {
                    PQ.pop();
                    PQ.push(PAIR(dist, p));
                }
            }
        }

        vector<vector<int>> result;
        while (!PQ.empty())
        {
            result.emplace_back(PQ.top().second);
            PQ.pop();
        }
        return result;
    }

void test_kClosest()
{
    vector<pair<vector<vector<int>>, int>> tc = { pair<vector<vector<int>>, int>({{1,3},{-2,2}}, 1),
                                                  pair<vector<vector<int>>, int>({{3,3},{5,-1},{-2,4}}, 2)};
    vector<vector<vector<int>>> answers = { {{-2, 2}},
                                            {{-2,4}, {3,3}}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (kClosest(tc[i].first, tc[i].second) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
