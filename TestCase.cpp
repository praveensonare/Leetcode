#include "91_DecodeWays.cpp"
#include "17_LetterCombination.h"
#include "Utility.h"

//17
void test_letterCombinations()
{
    vector<string> tc = {"23", "", "3", "2957"};
    vector<vector<string>> answers = {{"ad","bd","cd","ae","be","ce","af","bf","cf"},
                                 {},
                                 {"d","e","f"},
                                 {"awjp","bwjp","cwjp","axjp","bxjp","cxjp","ayjp","byjp","cyjp","azjp","bzjp","czjp","awkp","bwkp","cwkp","axkp","bxkp","cxkp","aykp","bykp","cykp","azkp","bzkp","czkp","awlp","bwlp","cwlp","axlp","bxlp","cxlp","aylp","bylp","cylp","azlp","bzlp","czlp","awjq","bwjq","cwjq","axjq","bxjq","cxjq","ayjq","byjq","cyjq","azjq","bzjq","czjq","awkq","bwkq","cwkq","axkq","bxkq","cxkq","aykq","bykq","cykq","azkq","bzkq","czkq","awlq","bwlq","cwlq","axlq","bxlq","cxlq","aylq","bylq","cylq","azlq","bzlq","czlq","awjr","bwjr","cwjr","axjr","bxjr","cxjr","ayjr","byjr","cyjr","azjr","bzjr","czjr","awkr","bwkr","cwkr","axkr","bxkr","cxkr","aykr","bykr","cykr","azkr","bzkr","czkr","awlr","bwlr","cwlr","axlr","bxlr","cxlr","aylr","bylr","cylr","azlr","bzlr","czlr","awjs","bwjs","cwjs","axjs","bxjs","cxjs","ayjs","byjs","cyjs","azjs","bzjs","czjs","awks","bwks","cwks","axks","bxks","cxks","ayks","byks","cyks","azks","bzks","czks","awls","bwls","cwls","axls","bxls","cxls","ayls","byls","cyls","azls","bzls","czls"}};
    auto comp = [](vector<string>& s1, vector<string>& s2)
    {
        if (s1.size() != s2.size()) return false;
        for (unsigned i = 0; i < s1.size(); ++i)
        {
            if (s1[i].compare(s2[i]) != 0) return false;
        }
        return true;
    };

    for (int idx = 0; idx < tc.size(); ++idx)
    {
        vector<string> ans = letterCombinations(tc[idx]);
        sort(ans.begin(), ans.end());
        sort(answers[idx].begin(), answers[idx].end());
        if(!comp(answers[idx], ans)) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
// 91
void test_numDecodings()
{
    vector <string> tc = {"12", "226" , "0", "1", "10", "111111111111111111111111111111111111111111111"};
    vector <int> answer = {2, 3, 0, 1, 1, 1836311903};

    int ans;
    for (int idx = 0; idx < tc.size(); ++idx)
    {
        Solution sol;
        ans = sol.numDecodings(tc[idx]);
        if (ans != answer[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

// 314
void test_verticalOrder()
{

}

// 445
void test_addTwoNumbers()
{
    vector<pair<vector<int>, vector<int>>> tc = {pair<vector<int>, vector<int>>({7,2,4,3}, {5,6,4}),
                                                 pair<vector<int>, vector<int>>({1}, {2})};
    vector<vector<int>> answers = {{7,8,0,7},
                                   {3}};
    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        ListNode* l = addTwoNumbers(GetListFromVector(tc[idx].first), GetListFromVector(tc[idx].second));
        if (!CompareList(l, GetListFromVector(answers[idx]))) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

// 563 Binary Tree Tilt
void test_findTilt()
{
    vector<string> tc = {"[1,2,3]", "[4,2,9,3,5,null,7]", "[21,7,14,1,1,2,2,3,3]"};
    vector<int> answers = {1, 15, 9};

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        TreeNode* head = DeSerialize(tc[idx]);
        if (findTilt(head) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }

}

//673
void test_findNumberOfLIS()
{
    vector<vector<int>> tc = {{1,3,5,4,7},
                              {2,2,2,2,2},
                              {1,2,4,3,5,4,7,2}
                             };

    vector<int> answer = {2, 5, 3};
    int ans;
    string status;

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        ans = findNumberOfLIS(tc[idx]);
        if (ans != answer[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

//785
void test_isBipartite()
{
    vector<vector<vector<int>>> graph = {{{1,3}, {0,2}, {1,3}, {0,2}},
                                         {{},{2,4,6}, {1,4,8,9}, {7,8}, {1,2,8,9}, {6,9}, {1,5,7,8,9}, {3,6,9}, {2,3,4,6,9}, {2,4,5,6,7,8}},
                                         {{1,2,3}, {0,2}, {0,1,3}, {0,2}}};
    vector <bool> answer = {true, false, false};

    bool ans;
    for (int idx = 0; idx < graph.size(); ++idx)
    {
        ans = isBipartite(graph[idx]);
        if (ans != answer[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
// 975
void test_oddEvenJumps()
{
    vector<vector<int>> tc = { {10,13,12,14,15}, {2,3,1,1,4}, {5,1,3,4,2} };
    vector<int> answers = {2, 3, 3};

    for (int idx = 0; idx < tc.size(); ++idx)
    {
        if (oddEvenJumps(tc[idx]) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

//1283
void test_smallestDivisor()
{
    vector<pair<vector<int>, int>> tc;
    tc.emplace_back(pair<vector<int>, int>({1,2,5,9}, 6));
    tc.emplace_back(pair<vector<int>, int>({2,3,5,7,11}, 11));
    tc.emplace_back(pair<vector<int>, int>({19}, 5));
    tc.emplace_back(pair<vector<int>, int>({1,2,3}, 6));
    vector<int>answer = {5, 3, 4, 1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (smallestDivisor(tc[i].first, tc[i].second) != answer[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
