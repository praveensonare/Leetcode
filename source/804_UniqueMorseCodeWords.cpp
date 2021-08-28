#include "Header.h"

// 804. Unique Morse Code Words
// Level - Easy
// 
// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
// 
// For convenience, the full table for the 26 letters of the English alphabet is given below:
// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// 
// Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatenation, the transformation of a word.
// Return the number of different transformations among all words we have.
// 
// Example:
// Input: words = ["gin", "zen", "gig", "msg"]
// Output: 2
// Explanation:
// The transformation of each word is:
// "gin" -> "--...-."
// "zen" -> "--...-."
// "gig" -> "--...--."
// "msg" -> "--...--."
// 
// There are 2 different transformations, "--...-." and "--...--.".
// Note:
// 
// The length of words will be at most 100.
// Each words[i] will have length in range [1, 12].
// words[i] will only consist of lowercase letters.

int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> H;
        for (auto w : words)
        {
            string str = "";
            for (auto c : w)
            {
                str += code[c-'a'];
            }
            H.insert(str);
        }
        return H.size();
    }

void test_uniqueMorseRepresentations()
{
    vector<vector<string>> tc = {{"gin", "zen", "gig", "msg"}};
    vector<int> answers = {2};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (uniqueMorseRepresentations(tc[i]) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
