#include "Utility.h"

// 1228. Missing Number In Arithmetic Progression
// Level - Easy
// In some array arr, the values were in arithmetic progression: the values arr[i+1] - arr[i] are all equal for every 0 <= i < arr.length - 1.
// Then, a value from arr was removed that was not the first or last value in the array.
// Return the removed value.
// 
// Example 1:
// Input: arr = [5,7,11,13]
// Output: 9
// Explanation: The previous array was [5,7,9,11,13].
// 
// Example 2:
// Input: arr = [15,13,12]
// Output: 14
// Explanation: The previous array was [15,14,13,12].

int missingNumber(vector<int>& arr) {
    int len = arr.size();
    int diff = (arr[len - 1] - arr[0]) / len;

    if (diff == 0) return arr.front();

    int expected = arr.front();
    for (auto& i : arr)
    {
        if (i != expected) return expected;

        expected += diff;
    }
    return 0;
}

void test_missingNumber()
{
    VVI tc = {{5,7,11,13}, {1,1,1}};
    VI answers = {9, 1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (missingNumber(tc[i]) != answers[i]) ERROR_LOG;
    }
}
