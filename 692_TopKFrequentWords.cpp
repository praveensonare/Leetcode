#include "Header.h"

// 692. Top K Frequent Words
// Level - Medium
// 
// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
// 
// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// 
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// 
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

#define PAIR pair<string, int>

bool IsPreferred(PAIR& a, PAIR& b)
{
    if (a.second > b.second) return true;
    else if (a.second == b.second) return a.first < b.first;
    else return false;
}

class mycomp
{
public:
    mycomp(){}
    bool operator() (PAIR& a, PAIR& b) { return IsPreferred(a, b); }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> H;
    for (auto w : words) ++H[w];

    priority_queue<PAIR, vector<PAIR>, mycomp> PQ;
    PAIR top;
    for (unordered_map<string, int>::iterator it = H.begin(); it != H.end(); ++it)
    {
        PAIR p(it->first, it->second);
        if (PQ.size() < (unsigned)k)
        {
            PQ.push(p);
        }
        else
        {
            top = PQ.top();
            if (IsPreferred(p, top))
            {
                PQ.pop();
                PQ.push(p);
            }
        }
    }

    vector<string> result;
    while (!PQ.empty())
    {
        top = PQ.top();
        result.push_back(top.first);
        PQ.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

void test_topKFrequent()
{
    vector<pair<vector<string>, int>> tc = {pair<vector<string>, int>({"i", "love", "leetcode", "i", "love", "coding"}, 2),
                                            pair<vector<string>, int>({"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4)};
    vector<vector<string>> answers = {{"i", "love"}, {"the", "is", "sunny", "day"}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (topKFrequent(tc[i].first, tc[i].second) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
