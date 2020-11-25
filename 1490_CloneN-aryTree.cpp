#include "Header.h"
// 1490. Clone N-ary Tree
// Level - Medium
// Given a root of an N-ary tree, return a deep copy (clone) of the tree.
// Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.
// Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
// 
// Follow up: Can your solution work for the graph problem?

class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};

Node* cloneTree(Node* root) {
    if (!root) return nullptr;

    unordered_map<Node*, Node*> H;
    Node* start = root;
    queue<Node*> Q;
    Q.push(root);

    Node* front;
    while (!Q.empty())
    {
        front = Q.front();
        H[front] = new Node(front->val);

        for (auto child : front->children)
        {
            if (child) Q.push(child);
        }

        Q.pop();
    }

    for (unordered_map<Node*, Node*>::iterator it = H.begin(); it != H.end(); ++it)
    {
        for (auto child : it->first->children)
        {
            it->second->children.push_back(H[child]);
        }
    }

    return H[root];
}

void test_cloneTree()
{

}
