#include "Header.h"

// 121. Best Time to Buy and Sell Stock
// Level - Easy
// 
// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
// Note that you cannot sell a stock before you buy one.
// 
// Example 1:
// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
// 
// Example 2:
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2) return 0;

    int profit = 0;
    int  minVal = prices[0];
    for (auto p : prices)
    {
        if (p < minVal) minVal = p;
        else profit = max(profit, p - minVal);
    }

    return profit;
}

void test_maxProfit()
{
    vector<vector<int>> tc = {{7,1,5,3,6,4}, {7,6,4,3,1}};
    vector<int> answers = {5, 0};

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        if (maxProfit(tc[idx]) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
