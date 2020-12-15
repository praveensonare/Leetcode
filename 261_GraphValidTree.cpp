#include "Utility.h"

// 261. Graph Valid Tree
// Level - Medium
// 
// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
// 
// Example 1:
// Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
// Output: true
// 
// Example 2:
// Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
// Output: false
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0) return true;

    vector<bool> visit(n, false);
    vector<unordered_set<int>> G(n);
    for (const auto& e : edges)
    {
        G[e[0]].insert(e[1]);
        G[e[1]].insert(e[0]);
    }

    int visitCount = 1;

    queue<int> Q;
    Q.push(0);
    visit[0] = true;
    int front;

    while (!Q.empty())
    {
        front = Q.front();
        for (auto c : G[front])
        {
            if (visit[c]) return false;

            G[c].erase(front);
            ++visitCount;
            visit[c] = true;
            Q.push(c);
        }
        Q.pop();
    }

    return (visitCount == n);
}

#define PAIR pair<int, vector<vector<int>>>
void test_validTree()
{
    vector<PAIR> tc = {PAIR(5,vector<vector<int>>({{0,1},{1,2},{2,3},{1,3},{1,4}})),
        PAIR(4, vector<vector<int>>({{0,1},{2,3},{1,2}})),
        PAIR(5, vector<vector<int>>({{0,1},{0,2},{0,3},{1,4}})),
        PAIR(3, vector<vector<int>>({{0,1}}))};
    vector<bool> answers = {false, true, true, false};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (validTree(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
