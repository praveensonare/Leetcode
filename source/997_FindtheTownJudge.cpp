#include "Header.h"

// 997. Find the Town Judge
// Level - Easy
// In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.
// If the town judge exists, then:
// 
// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
// If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
// 
// Example 1:
// Input: N = 2, trust = [[1,2]]
// Output: 2
// 
// Example 2:
// Input: N = 3, trust = [[1,3],[2,3]]
// Output: 3
// 
// Example 3:
// Input: N = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1
// 
// Example 4:
// Input: N = 3, trust = [[1,2],[2,3]]
// Output: -1
// 
// Example 5:
// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
// Output: 3
// 
// Constraints:
// 1 <= N <= 1000
// 0 <= trust.length <= 10^4
// trust[i].length == 2
// trust[i] are all different
// trust[i][0] != trust[i][1]
// 1 <= trust[i][0], trust[i][1] <= N
// 

#if 1
int findJudge(int N, vector<vector<int>>& trust) {
    vector<pair<int, int>> degree(N+1,pair<int,int>(0,0)); // in-out
    for (auto v : trust)
    {
        degree[v[0]].second++;
        degree[v[1]].first++;
    }

    for (int j=1; j <= N; ++j)
    {
        if (degree[j].first == N-1 && degree[j].second == 0) return j;
    }
    return -1;
}
#else
int findJudge(int N, vector<vector<int>>& trust) {
    vector<vector<bool>> trustMap(N+1, vector<bool>(N+1,false));
    for (auto v : trust)
    {
        trustMap[v[0]][v[1]] = true;
    }

    int judge = 1;
    for (int j = 2; j <= N; ++j)
    {
        if (trustMap[judge][j]) judge = j;
    }

    for (int j=1; j <=N; ++j)
    {
        if (judge == j) continue;
        if (trustMap[judge][j] || !trustMap[j][judge]) return -1;
    }
    return judge;
}
#endif
#define PAIR pair<int, vector<vector<int>>>
void test_findJudge()
{
    vector<PAIR> tc = {PAIR(2, vector<vector<int>>({{1,2}})),
                                               PAIR(3, vector<vector<int>>({{1,2},{2,3}})),
                                               PAIR(3, vector<vector<int>>({{1,3},{2,3}})),
                                               PAIR(3, vector<vector<int>>({{1,3},{2,3},{3,1}})),
                                               PAIR(4, vector<vector<int>>({{1,3},{1,4},{2,3},{2,4},{4,3}}))

    };
    vector<int> answers = { 2,-1,3,-1,3};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (findJudge(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
