#include "Utility.h"

// 98. Validate Binary Search Tree
// Level - Medium
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// 
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// 
// Example 1:
//         2
//       /   \
//     1       3
// Input: root = [2,1,3]
// Output: true
// 
// Example 2:
//             5
//            /  \
//         1       4
//               /   \
//             3       6
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
// 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

bool Validate(TreeNode* n, long minVal, long maxVal)
{
    if (!n) return true;

    if (n->val <= minVal || n->val >= maxVal) return false;

    return (Validate(n->left, minVal, n->val) && Validate(n->right, n->val, maxVal));
}
bool isValidBST(TreeNode* root) {
    return Validate(root, INT_MIN-(long)1, INT_MAX+(long)1);
}

void test_isValidBST()
{
    VS tc = {"[2,1,3]", "[5,1,4,null,null,3,6]", "[2147483647]", "[0]"};
    vector<bool> answers = {true, false, true, true};

    for (unsigned i = 0 ; i < tc.size(); ++i)
    {
        if (answers[i] != isValidBST(DeSerializeTree(tc[i]))) ERROR_LOG;
    }
}
