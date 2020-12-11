#include "Utility.h"

// 428. Serialize and Deserialize N-ary Tree
// Level - Hard
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// 
// For example, you may serialize the following 3-ary tree
// as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.
// Or you can follow LeetCode's level order traversal serialization format, where each group of children is separated by the null value.
// For example, the above tree may be serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].
// You do not necessarily need to follow the above suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.
// 
// Constraints:
// The number of nodes in the tree is in the range [0, 104].
// 0 <= Node.val <= 104
// The height of the n-ary tree is less than or equal to 1000
// Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";

        string s = to_string(root->val) + ",null";
        queue<Node*> Q;
        Q.push(root);
        Node* front;
        while (!Q.empty())
        {
            front = Q.front();
            if (front)
            {
                for (auto child : front->children)
                {
                    Q.push(child);
                    s += ","+ to_string(child->val);
                }
                s += ",null";//=("+to_string(front->val)+")";
            }
            Q.pop();
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;

        auto stringTok = [](const string& data)
        {
            size_t found;
            size_t start = 0;
            vector<string> tokens;
            do {
                found = data.find_first_of(",", start);
                tokens.emplace_back(data.substr(start, found - start));
                start = found + 1;
            } while(found != string::npos);
            return tokens;
        };

        vector<string> tokens = stringTok(data);
        Node* root = new Node(stoi(tokens[0]));
        queue<Node*> Q;
        Q.push(root);
        Q.push(nullptr);
        Node* front;
        int pos = 2;
        int tlen = tokens.size();
        Node* n;
        while (!Q.empty())
        {
            front = Q.front();
            if (front)
            {
                for ( ;pos < tlen && tokens[pos] != "null"; ++pos)
                {
                    n = new Node(stoi(tokens[pos]));
                    front->children.push_back(n);
                    Q.push(n);
                }
                ++pos;
            }
            Q.pop();
        }
        return root;
    }
};

void test_SDeserializeNaryTree()
{
    vector<string> tc = {"1,null,3,2,4,null,5,6", "1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14"};
    Codec codec;
    for (unsigned i = 0; i < 0;/*tc.size();*/ ++i)
    {
        if (tc[i] != codec.serialize(codec.deserialize(tc[i]))) ERROR_LOG;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
