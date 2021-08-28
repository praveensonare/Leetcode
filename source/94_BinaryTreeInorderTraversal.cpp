#include "Utility.h"

// 94. Binary Tree Inorder Traversal
// Level - Medium
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// 
// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]
// 
// Example 2:
// Input: root = []
// Output: []
// 
// Example 3:
// Input: root = [1]
// Output: [1]
// 
// Example 4:
// Input: root = [1,2]
// Output: [2,1]
// 
// Example 5:
// Input: root = [1,null,2]
// Output: [1,2]
// 
// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return {}; vector<int>pre;
    stack<TreeNode*>st; st.push(root);

    while(!st.empty()){
        auto x=st.top();
        if (!x->left)
        {
            pre.push_back(x->val);
            st.pop();
            if(x->right)
            {
                st.push(x->right);
                x->right = nullptr;
            }
        }
        else {
            st.push(x->left);
            x->left = nullptr;
        }
    }
    return pre;
}

void test_inorderTraversal()
{
    vector<string> tc = {"[1,null,2,3]", "[]", "[1]", "[1,2]", "[1,null,2]"};
    vector<vector<int>> answers = {{1,3,2}, {}, {1}, {2,1}, {1,2}};

    for (unsigned idx = 1; idx < tc.size(); ++idx)
    {
        TreeNode* head = DeSerializeTree(tc[idx]);
        if (inorderTraversal(head) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
