#include "91_DecodeWays.cpp"
// 91
void test_numDecodings()
{
    vector <string> tc = {"12", "226" , "0", "1", "10", "111111111111111111111111111111111111111111111"};
    vector <int> answer = {2, 3, 0, 1, 1, 1836311903};

    int ans;
    string status;
    for (int idx = 0; idx < tc.size(); ++idx)
    {
        Solution sol;
        ans = sol.numDecodings(tc[idx]);
        status = (ans == answer[idx]) ? "Passed" : "Failed";
        cout << "numDecodings : Test_" << idx << " : " << status <<endl;
    }
}

// 314
void test_verticalOrder()
{

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
        status = (ans == answer[idx]) ? "Passed" : "Failed";
        cout << "findNumberOfLIS Test_" << idx << " : " << status <<endl;
    }
}

//785
void test_isBipartite()
{
    vector<vector<vector<int>>> graph = {{{1,3}, {0,2}, {1,3}, {0,2}},
                                         {{},{2,4,6}, {1,4,8,9}, {7,8}, {1,2,8,9}, {6,9}, {1,5,7,8,9}, {3,6,9}, {2,3,4,6,9}, {2,4,5,6,7,8}},
                                         {{1,2,3}, {0,2}, {0,1,3}, {0,2}}};
    vector <bool> answer = {true, false, false};
    string status;

    bool ans;
    for (int idx = 0; idx < graph.size(); ++idx)
    {
        ans = isBipartite(graph[idx]);
        status = (ans == answer[idx]) ? "Passed" : "Failed";
        cout << "isBipartite : Test_" << idx << " : " << status <<endl;
    }
}
