#pragma once

#include "Header.h"

#if 0
Level - Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
#endif

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> M;
    M['2'] = {'a', 'b', 'c'};
    M['3'] = {'d', 'e', 'f'};
    M['4'] = {'g', 'h', 'i'};
    M['5'] = {'j', 'k', 'l'};
    M['6'] = {'m', 'n', 'o'};
    M['7'] = {'p', 'q', 'r', 's'};
    M['8'] = {'t', 'u', 'v'};
    M['9'] = {'w', 'x', 'y', 'z'};

    vector<string> result;
    int len;
    string lstr;
    for (auto c : digits)
    {
        len = result.size();
        vector<string> new_result;

        for( auto t : M[c])
        {
            for (int i = 0; i < len; ++i)
            {
                new_result.emplace_back(result[i]+string(1,t));
            }
        }

        if (len == 0)
        {
            for( auto t : M[c])
            new_result.emplace_back(string(1,t));
        }
        result = new_result;
    }

    return result;

}
