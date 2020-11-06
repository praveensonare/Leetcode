#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// 91
int numDecodings(string s);
void test_numDecodings();
// 314
vector<vector<int>> verticalOrder(TreeNode* root) ;
void test_verticalOrder();

//673
int findNumberOfLIS(vector<int>& nums);
void test_findNumberOfLIS();

//785
bool isBipartite(vector<vector<int>>& graph);
void test_isBipartite();

//314
