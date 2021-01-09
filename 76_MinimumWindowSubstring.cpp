#include "Utility.h"

// 76. Minimum Window Substring
// Level - Hard
// 
// Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
// Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
// 
// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// 
// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
// 
// Constraints:
// 1 <= s.length, t.length <= 105
// s and t consist of English letters.
// 
// Follow up: Could you find an algorithm that runs in O(n) time?

string minWindow(string s, string t)
{
    unordered_map<char,int> hashT;
    for (auto c : t) hashT[c]++;

    int len = s.length();
    unordered_map<char,int> hashSliding;
    pair<int,int> win(-1,0);
    pair<int,int> ans(-1, len-1);

    int count = 0, tlen = t.size();

    for (int i = 0; i < len; ++i)
    {
        if (hashT.find(s[i]) != hashT.end())
        {
            hashSliding[s[i]]++;
            if (count == tlen)
            {
                win.second = i;
                for (int j = win.first; j < i; ++j)
                {
                    if (hashT.find(s[j]) != hashT.end())
                    {
                        if (hashSliding[s[j]] > hashT[s[j]])
                        {
                            hashSliding[s[j]]--;
                        }
                        else
                        {
                            win.first = j;
                            break;
                        }
                    }
                }
                ans = (ans.second - ans.first < win.second - win.first) ? ans : win;
            }
            else
            {

                if (win.first == -1) win.first = i;

                if (hashSliding[s[i]] <= hashT[s[i]])
                {
                    ++count;
                    if (count == tlen)
                    {
                        win.second = i;
                        if (hashSliding[s[win.first]] > hashT[s[win.first]])
                        {
                            for (int j = win.first; j < i; ++j)
                            {
                                if (hashT.find(s[j]) != hashT.end())
                                {
                                    if (hashSliding[s[j]] > hashT[s[j]]) hashSliding[s[j]]--;
                                    else
                                    {
                                        win.first = j;
                                        break;
                                    }
                                }
                            }
                        }
                        ans = win;
                    }
                }
            }
        }

    }


    return (ans.first == -1) ? "" : s.substr(ans.first, ans.second - ans.first + 1);
}

void test_minWindow()
{
    vector<PAIR_SS> tc = {PAIR_SS("ADOBECODEBANC","ABC"), PAIR_SS("a","a")};
    vector<string> answer = {"BANC", "a"};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        string ans = minWindow(tc[i].first, tc[i].second);
        if (ans != answer[i]) ERROR_LOG;
    }
}
