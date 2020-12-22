#include "Utility.h"

// 1602. Find Nearest Right Node in Binary Tree
// Level - Medium
// Given the root of a binary tree and a node u in the tree, return the nearest node on the same level that is to the right of u, or return null if u is the rightmost node in its level.
// 
// Example 1:
//             1
//           /   \
//         2       3
//          \     /  \
//           4   5     6
// 
// Input: root = [1,2,3,null,4,5,6], u = 4
// Output: 5
// Explanation: The nearest node on the same level to the right of node 4 is node 5.
// 
// Example 2:
// 
//             3
//               \
//                 4
//                /
//              2
// 
// Input: root = [3,null,4,2], u = 2
// Output: null
// Explanation: There are no nodes to the right of 2.
// 
// Example 3:
// Input: root = [1], u = 1
// Output: null
// 
// Example 4:
// Input: root = [3,4,2,null,null,null,1], u = 4
// Output: 2
// 
// Constraints:
// 
// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 105
// All values in the tree are distinct.
// u is a node in the binary tree rooted at root.

TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    if (!root) return nullptr;

    queue<TreeNode*> Q;
    Q.push(root);
    Q.push(nullptr);

    auto addNode = [](TreeNode* t, queue<TreeNode*>& Q) {
        if(t) Q.push(t);
    };
    TreeNode* front;
    TreeNode* prev = nullptr;
    while (!Q.empty())
    {
        front = Q.front();
        Q.pop();
        if (u == prev) return front;
        if (Q.size() == 0) break;
        if (front)
        {
            addNode(front->left, Q);
            addNode(front->right, Q);
        }
        else
        {
            Q.push(nullptr);
        }

        prev = front;
    }
    return nullptr;
}

void test_findNearestRightNode()
{
    vector<pair<string, string>> tc = {pair<string, string>("[17,14,5,null,7,null,12,3,null,9,19]","[3]"),
                          pair<string, string>("[1,2,3,null,4,5,6]","[4]"),
                          pair<string, string>("[3,null,4,2]","[2]"),
                          pair<string, string>("[1]","[1]"),
                          pair<string, string>("[3,4,2,null,null,null,1]","[4]")};
    vector<string> answers = {"[9]","[5]","[]","[]","[2]"};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
    }
}
