#include "Header.h"

// 941. Valid Mountain Array
// Level - Easy
// Given an array of integers arr, return true if and only if it is a valid mountain array.
// 
// Recall that arr is a mountain array if and only if:
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < A[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// 
// Example 1:
// Input: arr = [2,1]
// Output: false
// 
// Example 2:
// Input: arr = [3,5,5]
// Output: false
// 
// Example 3:
// Input: arr = [0,3,2,1]
// Output: true
//  
// Constraints:
// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104
//

bool validMountainArray(vector<int>& A) {
	int len = A.size();
	if (len < 3) return false;

	int lmax = 0;
	int lmin = 0;

	for (int i = 2; i < len; ++i)
	{
		if (A[i] == A[i-1]) return false;
		if (A[i-2] < A[i-1] && A[i] < A[i-1]) ++lmax;
		else if (A[i-2] > A[i-1] && A[i] > A[i-1]) ++lmin;

		if (lmin > 0 || lmax > 1) return false; 
	}
	return (lmax == 1);
}

void test_validMountainArray()
{
    vector<vector<int>> tc = {{2,1}, {3,5,5}, {1,2,3,4,5}, {0,3,2,1}};
    vector<bool> answers = {false, false, false, true};

    for (int idx = 0; idx < tc.size(); ++idx)
    {
        if (validMountainArray(tc[idx]) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
/*
tc = {{2,1}, {3,5,5}, {1,2,3,4,5}, {0,3,2,1}};
answers = {false, false, false,, true};
*/
