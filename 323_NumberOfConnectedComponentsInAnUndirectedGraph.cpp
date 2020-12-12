#include "Utility.h"

// 323. Number of Connected Components in an Undirected Graph
// Level - Medium
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
// 
// Example 1:
// Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]
// 
//      0          3
//      |          |
//      1 --- 2    4
// 
// Output: 2
// 
// Example 2:
// Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
// 
//      0           4
//      |           |
//      1 --- 2 --- 3
// Output:  1
// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
// 

int countComponents(int n, vector<vector<int>>& edges) {
    vector<bool> visit(n, false);
    vector<vector<int>> G(n);
    for (const auto& e : edges)
    {
        G[e[0]].emplace_back(e[1]);
        G[e[1]].emplace_back(e[0]);
    }

    int component = 0;
    for (int i = 0; i < n; ++i)
    {
        if (visit[i]) continue;

        ++component;
        queue<int> Q;
        Q.push(i);
        visit[i] = true;
        int front;
        while (!Q.empty())
        {
            front = Q.front();
            for (auto c : G[front])
            {
                if (visit[c]) continue;

                visit[c] = true;
                Q.push(c);
            }
            Q.pop();
        }

    }

    return component;
}

#define PAIR pair<int, vector<vector<int>>>
void test_countComponents()
{
    vector<PAIR> tc = {PAIR(5, vector<vector<int>>({{0,1},{1,2},{3,4}})),
        PAIR(5, vector<vector<int>>({{0,1},{1,2},{2,3},{3,4}}))};
    vector<int> answers = {2,1};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (countComponents(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
