#include "Header.h"
#include "Utility.h"

// 117. Populating Next Right Pointers in Each Node II
// Level - Medium
// 
// Given a binary tree
// 
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
// 
// Follow up:
// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
// 
// Example 1:
// Input: root = [1,2,3,4,5,null,7]
//          1
//       /    \
//      2      3
//    /   \      \
//   4     5      7
// Output: [1,#,2,3,#,4,5,7,#]
//          1 -> null
//       /    \
//      2  ->   3 -> null
//    /   \      \
//   4 ->  5  ->  7 -> null
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// 
// Constraints:
// The number of nodes in the given tree is less than 6000.
// -100 <= node.val <= 100

Node* UpdateList(Node* nextList, Node* n)
{
    if (!nextList) return n;
    if (!n) return nextList;

    nextList->next = n;
    nextList = nextList->next;

    return nextList;
}

Node* connect(Node* root) {
    if (!root) return root;

    Node* answer = root;
    root->next = nullptr;
    while (root)
    {
        Node* nextList = nullptr;
        Node* nextHead = nullptr;
        for (; root; root = root->next)
        {
            nextList = UpdateList(nextList, root->left);
            if (!nextHead) nextHead = nextList;
            nextList = UpdateList(nextList, root->right);
            if (!nextHead) nextHead = nextList;
        }
        if (nextList) nextList->next = nullptr;
        root = nextHead;
    }

    return answer;
}

void test_connect()
{
    vector<string> tc = {"[1,2,3,4,5,null,7]"};
    vector<string> answers = {"[1,#,2,3,#,4,5,7,#]"};

    for (unsigned idx = 1; idx < tc.size(); ++idx)
    {
        TreeNode* head = DeSerializeTree(tc[idx]);
            //if (!CompareTree(increasingBST(head), DeSerializeTree(answers[idx]))) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
