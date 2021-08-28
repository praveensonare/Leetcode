#include "Header.h"

// 43. Multiply Strings
// Level - Medium
// 
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
// 
// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"
// 
// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"
// 
// Constraints:
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

void add(string& num1, string& num2)
{
    int len = num1.length();
    int carry = 0;
    int num = 0;
    for (int i = len - 1; i >=0; --i)
    {
        num = (num2[i]-'0') + (num1[i]-'0') + carry;
        carry = num / 10;
        num1[i] = (num % 10) + '0';
    }
}

string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    string result = string(len1 + len2, '0');
    string temp = string(len1 + len2, '0');
    int carry;
    int num;
    //cout << "temp: " << temp <<"\tresult: "<<result << "\t len: "<<len1<<" "<<len2<< endl;
    int offset;
    for (int i = len2 - 1; i >= 0; --i)
    {
        carry = 0;
        offset = len1 + len2 - 1 - (len2 - 1 - i);
        temp = string(len1 + len2, '0');;
        for (int j = len1 - 1; j >= 0; --j)
        {
            num = (num2[i]-'0') * (num1[j]-'0') + carry;
            carry = num/10;
            num = num % 10;
            temp[offset - (len1 - 1 - j)] = '0' + num;
        }

        if (carry != 0) temp[offset - len1] = '0' + carry;
        add(result, temp);
    }
    size_t found = result.find_first_not_of('0');
    result = (found == string::npos) ? "0" : result.substr(found);
    return result;
}

void test_multiply()
{
    vector<pair<string, string>> tc = { pair<string, string>("9","99"),
                                        pair<string, string>("99","9"),
                                        pair<string, string>("9", "9"),
                                        pair<string, string>("123", "456"),
                                        pair<string, string>("2", "3"),
                                        pair<string, string>("76240047126666041961133788375854678695507175099108423713540245804984464373874905749210597511224714", "50508987390094918079940272645150122130992191514531426745139766970214425636907460704571014980779812464")};

    vector<string> answers = { "891",
                               "891",
                               "81",
                               "56088",
                               "6",
                               "3850807578941017405043936428334617006206578681059793185019338920318752709804789931220097477302896139962461703898399750453490343458217019930720602316843466382402743174163712702358367940356131882035296"
                              };
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (multiply(tc[i].first, tc[i].second) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
