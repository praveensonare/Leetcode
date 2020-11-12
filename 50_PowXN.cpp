#include "Header.h"

unordered_map<int, double> dp;
double Power(double x, int n)
{
    if (dp.find(n) != dp.end()) return dp[n];
    dp[n] = Power(x, n/2) * Power(x, n/2) * Power(x, n%2);
    return dp[n];
}

double myPow(double x, int n) {
    dp = unordered_map<int, double>();
    dp[0]  = 1;
    dp[-1] = 1/x;
    dp[1]  = x;
    return Power(x, n);
}
