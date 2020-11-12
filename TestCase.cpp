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
// 19
void test_removeNthFromEnd()
{
    vector<pair<string, string>> tc = {pair<string, string>("[7,2,4,3]", "[5,6,4]"),
                                                 pair<string, string>("[1]", "[2]")};
    vector<string> answers = {"[7,8,0,7]",
                                   "[3]"};
    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        ListNode* l = addTwoNumbers(DeSerializeList(tc[idx].first), DeSerializeList(tc[idx].second));
        if (!CompareList(l, DeSerializeList(answers[idx]))) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

// 23 Merge K Sorted Lists
void test_mergeKLists()
{
    vector<vector<string>> tc = {{"[1,4,5]","[1,3,4]","[2,6]"},{"[]"}} ;
    vector<string> answers = {"[1,1,2,3,4,4,5,6]", "[]"};


    for (unsigned i = 0; i < tc.size(); ++i)
    {
        vector<ListNode*> tc_List(tc[i].size(), nullptr);
        for (unsigned j = 0; j < tc[i].size(); ++j)
        {
            tc_List[j] = DeSerializeList(tc[i][j]);
        }

        if (!CompareList(mergeKLists(tc_List) , DeSerializeList(answers[i]))) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}

//50
void test_myPow()
{
    vector<pair<double, int>> tc = { pair<double, int>(34.00515, -3),
                        pair<double, int>(2.00000, 10),
                        pair<double, int>(2.10000, 3),
                        pair<double, int>(2.00000, -2)
                      };
    vector<double> answers = {0.00003, 1024.00000, 9.26100, 0.25000};

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        if (myPow(tc[idx].first, tc[idx].second) != answers[idx])
        {
            // result is platform dependent, hence doesn't work correctly everywhere.
           // cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
        }
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

// 299 Bulls and Cows
void test_getHint()
{
    vector<pair<string, string>> tc = {pair<string, string>("1807", "7810"),
                                       pair<string, string>("1123", "0111"),
                                       pair<string, string>("1", "0"),
                                       pair<string, string>("1", "1")
                                      };
    vector<string> answers = {"1A3B", "1A1B", "0A0B", "1A0B"};

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        if (getHint(tc[idx].first, tc[idx].second) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

// 314
void test_verticalOrder()
{

}

// 445
void test_addTwoNumbers()
{
    vector<pair<string, string>> tc = {pair<string, string>("[7,2,4,3]", "[5,6,4]"),
                                                 pair<string, string>("[1]", "[2]")};
    vector<string> answers = {"[7,8,0,7]",
                                   "[3]"};
    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        ListNode* l = addTwoNumbers(DeSerializeList(tc[idx].first), DeSerializeList(tc[idx].second));
        if (!CompareList(l, DeSerializeList(answers[idx]))) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

// 563 Binary Tree Tilt
void test_findTilt()
{
    vector<string> tc = {"[1,2,3]", "[4,2,9,3,5,null,7]", "[21,7,14,1,1,2,2,3,3]"};
    vector<int> answers = {1, 15, 9};

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        TreeNode* head = DeSerializeTree(tc[idx]);
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

//1026 Max_difference between node and ancestor
void test_maxAncestorDiff()
{
    vector<string> tc = {"[8,3,10,1,6,null,14,null,null,4,7,13]", "[1,null,2,null,0,3]"};
    vector<int> answers = {7, 3};

    for (int idx = 0; idx < tc.size(); ++idx)
    {
        if (maxAncestorDiff(DeSerializeTree(tc[idx])) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
// 1099 Two Sum Less than K
void test_twoSumLessThanK()
{
    vector<pair<vector<int>, int>> tc = {pair<vector<int>, int>({34,23,1,24,75,33,54,8}, 60),
                                         pair<vector<int>, int>({10,20,30}, 15),
                                         pair<vector<int>, int>({254,914,110,900,147,441,209,122,571,942,136,350,160,127,178,839,201,386,462,45,735,467,153,415,875,282,204,534,639,994,284,320,865,468,1,838,275,370,295,574,309,268,415,385,786,62,359,78,854,944}, 200),
                                         pair<vector<int>, int>({803,468,292,154,924,424,197,277,753,86,984,144,105,450,287,265,655,404,407,794,513,976,241,272,84,503,65,654,805,413,362,907,297,473,113,567,646,607,806,674,424,753,870,574,765,170,603,696,513,58}, 300)
                                        };
    vector<int> answer = {58, -1, 198, 299};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (twoSumLessThanK(tc[i].first, tc[i].second) != answer[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
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
