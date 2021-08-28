#include "Header.h"

vector<int> water_pockets(const vector<int>& landscape)
{
    int len = landscape.size();
    if (len < 3) return {};

    vector<int> Lmax(len, landscape.front()), Rmax(len, landscape.back());
    int last = len -1;
    for (int i = 1; i < len; ++i)
    {
        Lmax[i] = max(Lmax[i-1], landscape[i]);
        Rmax[last - i] = max(Rmax[last - i + 1], landscape[last - i]);
    }

    vector<int> result;
    int sum = 0;
    int trap;
    for (int i = 0; i < len; ++i)
    {
        trap = min(Lmax[i], Rmax[i]) - landscape[i];
        if (trap > 0)
        {
            sum += trap;
        }
        else
        {
            if (sum > 0) result.push_back(sum);
            sum = 0;
        }
    }

    return result;
}

void test_water_pockets()
{
    vector<vector<int>> tc {
      {4, 1, 2, 3, 0, 2},
      {5, 3, 8},
      {4, 5},
      {4, 2, 0, 3, 2, 5}
    };

    vector<vector<int>> ans {
      {3, 2},
      {2},
      {},
      {9}
    };

    //water_pockets({4, 2, 0, 1, 2, 5});
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (water_pockets(tc[i]) != ans[i])
        {
            cout << "FAILED TEST_" << i << endl;
            //cout << __FUNCTION__ << " Test_" << i << " => FAILED" << endl;
        }
    }
}
