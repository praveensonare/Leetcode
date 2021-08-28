#include "Header.h"

bool isBipartite(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<int> color(len, 0);

    queue<int> Q;

    int front;
    int col;
    for (int i = 0; i < len; ++i)
    {
        if (color[i] != 0) continue;

        color[i] = 1;
        Q.push(i);
        while (!Q.empty())
        {
            front = Q.front();
            col = (color[front] == 1) ? 2 : 1;
            for (auto n : graph[front])
            {
                if (color[front] == color[n]) return false;
                if (color[n] != 0) continue;

                color[n] = col;
                Q.push(n);
            }
            Q.pop();
        }
    }
    return true;
}

#if 0
Intuition

Color a node blue if it is part of the first set, else red. We should be able to greedily color the graph if and only if it is bipartite: one node being blue implies all it's neighbors are red, all those neighbors are blue, and so on.


Diagram of coloring neighbors of nodes

Algorithm

We'll keep an array (or hashmap) to lookup the color of each node: color[node]. The colors could be 0, 1, or uncolored (-1 or null).

We should be careful to consider disconnected components of the graph, by searching each node. For each uncolored node, we'll start the coloring process by doing a depth-first-search on that node. Every neighbor gets colored the opposite color from the current node. If we find a neighbor colored the same color as the current node, then our coloring was impossible.

To perform the depth-first search, we use a stack. For each uncolored neighbor in graph[node], we'll color it and add it to our stack, which acts as a sort of "todo list" of nodes to visit next. Our larger loop for start... ensures that we color every node.


Complexity Analysis

Time Complexity: O(N + E)O(N+E), where NN is the number of nodes in the graph, and EE is the number of edges. We explore each node once when we transform it from uncolored to colored, traversing all its edges in the process.

Space Complexity: O(N)O(N), the space used to store the color.
#endif



