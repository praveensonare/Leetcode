#include "Header.h"
#include "Utility.h"

// 297. Serialize and Deserialize Binary Tree
// Level - Hard
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
// 
// Example 1:
// 
//         1
//       /   \
//     2       3
//           /   \
//         4       5
// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// 
// Example 2:
// Input: root = []
// Output: []
// 
// Example 3:
// Input: root = [1]
// Output: [1]
// 
// Example 4:
// Input: root = [1,2]
// Output: [1,2]
// 
// Constraints:
// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000
//

class Codec {
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if (!root) return "null";

            queue<TreeNode*> Q;
            Q.push(root);
            string s;
            TreeNode* front;
            while(!Q.empty())
            {
                front = Q.front();
                if (front)
                {
                    s += to_string(front->val) + " ";
                    Q.push(front->left);
                    Q.push(front->right);
                }
                else
                    s += "null ";

                Q.pop();
            }

            s.pop_back();
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {

            if (data.empty() || data == "null") return nullptr;

            auto stringTok = [](const string& data)
            {
                size_t found;
                size_t start = 0;
                vector<string> tokens;
                do {
                    found = data.find_first_of(" ", start);
                    tokens.emplace_back(data.substr(start, found - start));
                    start = found + 1;
                } while(found != string::npos);
                return tokens;
            };

            vector<string> tokens = stringTok(data);
            TreeNode* root = new TreeNode(std::stoi(tokens[0]));
            queue<TreeNode*> Q;
            Q.push(root);
            TreeNode* front;
            unsigned pos = 0;
            while (!Q.empty())
            {
                front = Q.front();
                ++pos;
                if (pos < tokens.size() && "null" != tokens[pos])
                {
                    front->left = new TreeNode(stoi(tokens[pos]));
                    Q.push(front->left);
                }
                ++pos;
                if (pos < tokens.size() && "null" != tokens[pos])
                {
                    front->right = new TreeNode(stoi(tokens[pos]));
                    Q.push(front->right);
                }

                Q.pop();
            }

            return root;
        }
};

void test_SDeserializeBinaryTree()
{
    vector<string> tc = {"[1,2,3,null,null,4,5]", "[]", "[1]", "[1,2]"};
    Codec codec;
    TreeNode* t;
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        t = DeSerializeTree(tc[i]);
        if (!CompareTree(t, codec.deserialize(codec.serialize(t)))) ERROR_LOG;
    }
}
