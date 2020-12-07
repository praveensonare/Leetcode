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

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random, Node *next) : val(x), left(left), right(right), random(random), next(next) {}
};

#define ERROR_LOG cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
#define INFO_LOG  cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>SUCCESS"<< endl;

TreeNode* GetTree(const string& s);

void test_lengthOfLongestSubstring();               // 3. Longest Substring Without Repeating Characters
void test_maxArea();                                // 11. Container with most water
// 17
void test_letterCombinations();

// 19 Remove Nth Node From the End of the List
ListNode* removeNthFromEnd(ListNode* head, int n);
void test_removeNthFromEnd();

// 23. Merge k Sorted Lists
ListNode* mergeKLists(vector<ListNode*>& lists);
void test_mergeKLists();

void test_nextPermutation();                        // 31. Next Permutation
void test_multiply();                               // 43. Multiply Strings
// 50 Pow(x, n)
double myPow(double x, int n);
void test_myPow();
void test_canJump();                                // 55 Jump Game
// 56 Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals);
void test_merge();

// 91
int numDecodings(string s);
void test_numDecodings();
void test_connect();                                    // 117. Populating Next Right Pointers in Each Node II
// 121. Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices);
void test_maxProfit();

// 122. Best Time to Buy and Sell Stock II
int maxProfit2(vector<int>& prices);
void test_maxProfit2();
void test_copyRandomList();                             // 138. Copy List with Random Pointer
void test_lengthOfLongestSubstringTwoDistinct();        // 159. Longest Substring with At Most Two Distinct Characters
void findMissingRanges();                               // 163. Missing Ranges
void test_rob();                                        // 198 House Robber
// 200 Number Of Islands
int numIslands(vector<vector<char>>& grid);
void test_numIslands();
void test_rob_circular();                               // 213 House Robber II
// 215 Kth Largest element
void test_findKthLargest();
void test_maxSlidingWindow();                           // 239. Sliding Window Maximum
void test_shortestDistance();                           // 243. Shortest Word Distance
// 299 Bulls and cows
string getHint(string secret, string guess);
void test_getHint();
// 314
vector<vector<int>> verticalOrder(TreeNode* root) ;
void test_verticalOrder();

void test_longestSubstring();                           // 395.Longest Substring with At Least K Repeating Characters
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
void test_kthGrammar();                     // 779. K-th Symbol in Grammar
void test_uniqueMorseRepresentations();     // 804. Unique Morse Code Words
void test_backspaceCompare();               // 844. Backspace String Compare
// 845
int longestMountain(vector<int>& A) ;
void test_longestMountain();
void test_increasingBST();                  // 897. Increasing Order Search Tree
// 902
void test_atMostNGivenDigitSet();

//938
int rangeSumBST(TreeNode* root, int low, int high);
void test_rangeSumBST();

// 941
bool validMountainArray(vector<int>& A);
void test_validMountainArray();

void test_kClosest();                       // 973. K Closest Points to Origin
//975 Odd Even Jump
int oddEvenJumps(vector<int>& A);
void test_oddEvenJumps();

void test_smallestRepunitDivByK();          // 1015 Smallest Integer Divisible by K
// 1026 Maximum Difference between ancestor and node
int maxAncestorDiff(TreeNode* root);
void test_maxAncestorDiff();

// 1099 Two Sum Less Than K
int twoSumLessThanK(vector<int>& A, int K);
void test_twoSumLessThanK();

void test_delNodes();                       // 1110. Delete Nodes And Return Forest
// 1272 Remove Interval
vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved);
void test_removeInterval();

//1283
int smallestDivisor(vector<int>& nums, int threshold);
void test_smallestDivisor();

void test_canReach();                       // 1306. Jump Game III
void test_copyRandomBinaryTree();           // 1485. Clone Binary Tree With Random Pointer
void test_cloneTree();                      // 1490. Clone N-ary Tree

//Design
void test_LRUCache();           // 146
void test_MinStack();           // 155
void test_LoggerRateLitter();   // 359
