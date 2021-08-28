#include "Header.h"

// 1110. Delete Nodes And Return Forest
// Level -Medium
// 
// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest.  You may return the result in any order.
// 
// Example 1:
// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
// 
// Constraints:
// The number of nodes in the given tree is at most 1000.
// Each node has a distinct value between 1 and 1000.
// to_delete.length <= 1000
// to_delete contains distinct values between 1 and 1000.

void help(TreeNode* root, const unordered_set<int>& H, vector<TreeNode*>& result, TreeNode* par)
{
    if (!root) return;

    if (H.find(root->val) != H.end())
    {
        if (par)
        {
            if (par->left && par->left->val == root->val) par->left = nullptr;
            else if (par->right && par->right->val == root->val) par->right = nullptr;
        }
        help(root->left,  H, result, nullptr);
        help(root->right, H, result, nullptr);
    }
    else
    {
        if(!par) result.emplace_back(root);
        help(root->left,  H, result, root);
        help(root->right, H, result, root);
    }
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> result;
    unordered_set<int> H(to_delete.begin(), to_delete.end());
    //cout << H.size() << " " << to_delete.size() <<endl;

    help(root, H, result, nullptr);
    return result;
}

void test_delNodes()
{

}
