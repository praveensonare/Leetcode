#include "Utility.h"

// 1457. Pseudo-Palindromic Paths in a Binary Tree
// Level - Medium
// 
// Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
// Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
// 
// Example 1:
// Input: root = [2,3,1,3,1,null,1]
// Output: 2
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
// 
// Example 2:
// Input: root = [2,1,1,1,3,null,null,null,null,null,1]
// Output: 1
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
// 
// Example 3:
// Input: root = [9]
// Output: 1
// 
// Constraints:
// The given binary tree will have between 1 and 10^5 nodes.
// Node values are digits from 1 to 9.

int mcount = 0;
void help(TreeNode* n, unordered_set<int>& S)
{
    if (!n) return;

    if (S.find(n->val) != S.end()) S.erase(n->val);
    else S.insert(n->val);

    if (!n->left && !n->right)
    {
        mcount += (S.size() <= 1) ? 1 : 0;
    }


    help(n->left, S);
    help(n->right, S);
    if (S.find(n->val) != S.end()) S.erase(n->val);
    else S.insert(n->val);
}

int pseudoPalindromicPaths (TreeNode* root) {
    unordered_set<int> S;
    mcount = 0;
    help(root, S);
    return mcount;
}

void test_pseudoPalindromicPaths()
{
    VS tc = {"[2,3,1,3,1,null,1]", "[2,1,1,1,3,null,null,null,null,null,1]", "[9]"};
    VI answers = {2,1,1};

    for (unsigned i = 0; i < tc.size(), ++i;)
    {
        //if (pseudoPalindromicPaths(DeSerializeTree(tc[i])) != answers[i]) ERROR_LOG;
    }
}
