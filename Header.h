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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* GetTree(const string& s);

// 17
void test_letterCombinations();

// 19 Remove Nth Node From the End of the List
ListNode* removeNthFromEnd(ListNode* head, int n);
void test_removeNthFromEnd();

// 23. Merge k Sorted Lists
ListNode* mergeKLists(vector<ListNode*>& lists);
void test_mergeKLists();

// 50 Pow(x, n)
double myPow(double x, int n);
void test_myPow();

// 56 Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals);
void test_merge();

// 91
int numDecodings(string s);
void test_numDecodings();

// 121. Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices);
void test_maxProfit();

// 122. Best Time to Buy and Sell Stock II
int maxProfit2(vector<int>& prices);
void test_maxProfit2();

// 200 Number Of Islands
int numIslands(vector<vector<char>>& grid);
void test_numIslands();

// 215 Kth Largest element
void test_findKthLargest();

// 299 Bulls and cows
string getHint(string secret, string guess);
void test_getHint();
// 314
vector<vector<int>> verticalOrder(TreeNode* root) ;
void test_verticalOrder();

//445 Add Two Numbers II
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void test_addTwoNumbers();

// 563 Binary Tree Tilt
int findTilt(TreeNode* root);
void test_findTilt();

//673
int findNumberOfLIS(vector<int>& nums);
void test_findNumberOfLIS();

void test_topKFrequent();           // 692. Top K Frequent Words
//718 Maximum Length of Repeated Subarray
int findLength(vector<int>& A, vector<int>& B);
void test_findLength();

//785
bool isBipartite(vector<vector<int>>& graph);
void test_isBipartite();

// 845
int longestMountain(vector<int>& A) ;
void test_longestMountain();

// 902
void test_atMostNGivenDigitSet();

//938
int rangeSumBST(TreeNode* root, int low, int high);
void test_rangeSumBST();

// 941
bool validMountainArray(vector<int>& A);
void test_validMountainArray();

void test_kClosest();               // 973. K Closest Points to Origin
//975 Odd Even Jump
int oddEvenJumps(vector<int>& A);
void test_oddEvenJumps();

// 1026 Maximum Difference between ancestor and node
int maxAncestorDiff(TreeNode* root);
void test_maxAncestorDiff();

// 1099 Two Sum Less Than K
int twoSumLessThanK(vector<int>& A, int K);
void test_twoSumLessThanK();

// 1272 Remove Interval
vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved);
void test_removeInterval();

//1283
int smallestDivisor(vector<int>& nums, int threshold);
void test_smallestDivisor();


//Design
void test_LRUCache();           // 146
void test_MinStack();           // 155
void test_LoggerRateLitter();   // 359
