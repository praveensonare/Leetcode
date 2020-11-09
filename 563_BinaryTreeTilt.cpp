#include "Utility.h"

#if 0
563. Binary Tree Tilt
Level - Easy
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if there the node does not have a right child.
#endif

int findTiltSum(TreeNode* root, int& s)
{
    if (!root) return 0;

    int left  = findTiltSum(root->left,  s);
    int right = findTiltSum(root->right, s);
    s += std::abs(left-right);
    return root->val + left + right;
}

int findTilt(TreeNode* root) {
    int sum = 0;
    findTiltSum(root, sum);
    return sum;
}
