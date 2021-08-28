#include "Header.h"

// 1104. Path In Zigzag Labelled Binary Tree
// Level - Medium
// 
// In an infinite binary tree where every node has two children, the nodes are labelled in row order.
// In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.
// Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
// 
//           1
//         /    \
//      3          2
//     /  \       /  \
//   4     5     6    7
//  / \   / \   / \  / \
// 15 14 13 12 11 10 9  8
// 
// Example 1:
// Input: label = 14
// Output: [1,3,4,14]
// 
// Example 2:
// Input: label = 26
// Output: [1,2,6,10,26]
// 
// Constraints:
// 1 <= label <= 10^6

vector<int> pathInZigZagTree(int label) {
    if (label == 1) return {1};

    int level = log2(label);
    vector<int> result(level+1,0);
    int start = pow(2, level);
    int end = pow(2, level + 1)-1;
    int pos = 0;

    while(level >= 0){
        result[level] = label;
        pos = (level%2 == 0) ? label - start : end - label;
        --level;
        end = start - 1;
        start = pow(2, level);
        label = (level%2 == 0) ? start + pos/2 : end - pos/2;
    }

    return result;
}

void test_pathInZigZagTree()            // 1104. Path In Zigzag Labelled Binary Tree
{
    vector<int> tc = {14,26};
    vector<vector<int>> answers = {{1,3,4,14}, {1,2,6,10,26}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (pathInZigZagTree(tc[i]) != answers[i]) ERROR_LOG;
    }
}
