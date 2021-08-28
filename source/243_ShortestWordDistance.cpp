#include "Header.h"

// 243. Shortest Word Distance
// Level -Easy
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
// 
// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
// 
// Note: You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

int shortestDistance(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> H;
    int len = words.size();
    for (int i = 0; i < len; ++i)
    {
        H[words[i]].emplace_back(i);
    }

    vector<int> v1 = H[word1];
    vector<int> v2 = H[word2];

    int i1 = 0, i2 = 0;
    int l1 = v1.size(), l2 = v2.size();

    int diff = INT_MAX;
    while (i1 < l1 && i2 < l2)
    {
        if (v1[i1] == v2[i2]) return 0;

        if (v1[i1] < v2[i2])
        {
            diff = min(diff, v2[i2] - v1[i1]);
            ++i1;
        }
        else
        {
            diff = min(diff, v1[i1] - v2[i2]);
            ++i2;
        }
    }

    return diff;
}

class myObject{
    public:
    vector<string> words;
    string word1;
    string word2;

    myObject(vector<string> v, string w1, string w2): words(v), word1(w1), word2(w2) {}
};

void test_shortestDistance()
{
    vector<myObject> tc = {myObject({"practice", "makes", "perfect", "coding", "makes"}, "coding", "practice"),
                           myObject({"practice", "makes", "perfect", "coding", "makes"}, "makes", "coding")};

    vector<int> answers = {3, 1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (shortestDistance(tc[i].words, tc[i].word1, tc[i].word2) != answers[i]) ERROR_LOG;
    }
}
