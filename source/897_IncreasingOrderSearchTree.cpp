#include "Utility.h"

// 897. Increasing Order Search Tree
// Level - Easy
// 
// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
// 
// Example 1:
// Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// 
// Example 2:
// Input: root = [5,1,7]
// Output: [1,null,5,null,7]
// 
// Constraints:
// The number of nodes in the given tree will be in the range [1, 100].
// 0 <= Node.val <= 1000

TreeNode* head = nullptr;
TreeNode* p = nullptr;
TreeNode* help(TreeNode* root)
{
    if (!root) return nullptr;

    help(root->left);
    if (!head) p = head = root;
    else {
        p->right = root;
        p = p->right;
    }
    root->left = nullptr;
    help(root->right);
    return root;
}

TreeNode* increasingBST(TreeNode* root) {
    head = nullptr;
    p = nullptr;
    help(root);
    return head;
}

void test_increasingBST()
{
    vector<string> tc = {"[5,3,6,2,4,null,8,1,null,null,null,7,9]", "[5,1,7]", "[5,3,8,null,null,7,null]"};
    vector<string> answers = {"[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]", "[1,null,5,null,7]", "[3,null,5,null,7,null,8]"};

    for (unsigned idx = 1; idx < tc.size(); ++idx)
    {
        TreeNode* head = DeSerializeTree(tc[idx]);
        if (!CompareTree(increasingBST(head), DeSerializeTree(answers[idx]))) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
