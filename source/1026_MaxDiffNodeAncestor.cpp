#include "Header.h"

// Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
// A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.
// Level : MEDIUM
//
// Example 1:
//              8
//           /      \
//        3            10
//       /  \             \
//      1     6            14
//           /  \          /
//          4    7       13
//
// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
//
// Example 2:
//      1
//        \
//          2
//            \
//              0
//            /
//          3
//
// Input: root = [1,null,2,null,0,3]
// Output: 3
//

void getMaxDiff(TreeNode* root, int _max, int _min, int &v)
{
    if (!root) return;

    v = max(v, max(abs(root->val - _min), abs(root->val - _max)));
    getMaxDiff(root->left,  max(_max, root->val), min(_min, root->val), v);
    getMaxDiff(root->right, max(_max, root->val), min(_min, root->val), v);
}

int maxAncestorDiff(TreeNode* root) {
    if (!root) return 0;
    int v = INT_MIN;
    getMaxDiff(root, root->val, root->val, v);
    return v;
}
