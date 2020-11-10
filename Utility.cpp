#include "Header.h"

bool CompareList(ListNode* l1, ListNode* l2)
{
    while (1)
    {
        if (!l1 && !l2) return true;
        if ((l1 && !l2) || (!l1 && l2)) return false;
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
}

vector<string> GetStringValues(string s)
{
    if (s.empty()) return {};

    vector<string> result;
    std::size_t found = s.find_first_of(",");
    std::size_t prev = 0;
    while (found != string::npos) {
        result.emplace_back(s.substr(prev, found));
        prev = found + 1;
        found = s.find_first_of(",", prev);
    }
    return result;
}

TreeNode* GetTreeFromStringVec(vector<string>& strings)
{
    if (strings.empty() || strings[0] == "null") return nullptr;

    int len = strings.size();
    TreeNode* head = new TreeNode(std::stoi(strings[0]));
    queue<TreeNode*> Q;
    Q.push(head);
    TreeNode* front = nullptr;
    int idx = 1;

    while(!Q.empty())
    {
        front = Q.front();

        if (idx < len && strings[idx] != "null")
        {
            front->left = new TreeNode(std::stoi(strings[idx]));
            Q.push(front->left);
        }
        ++idx;

        if (idx < len && strings[idx] != "null")
        {
            front->right = new TreeNode(std::stoi(strings[idx]));
            Q.push(front->right);
        }
        ++idx;

        Q.pop();
    }

    return head;
}

vector<string> GetTokenizeStringByComma(string s)
{
    if (s.empty()) return {};
    // "[4,2,9,3,5,null,7]"
    s = s.substr(1, s.length()-2);
    vector<string> strings;
    size_t from = 0;
    size_t to;
    do
    {
        to = s.find_first_of(",", from);
        strings.emplace_back(s.substr(from, to - from));
        from = to + 1;
    }
    while(to != string::npos);
    return strings;
}

ListNode* GetListFromVectorString(const vector<string>& v)
{
    ListNode* head = nullptr;
    for (int idx = v.size() - 1; idx >= 0; --idx)
    {
        head = new ListNode(std::stoi(v[idx]), head);
    }
    return head;
}

ListNode* DeSerializeList(string s)
{
    vector<string> strings = GetTokenizeStringByComma(s);
    return GetListFromVectorString(strings);
}

TreeNode* DeSerializeTree(string s)
{
    vector<string> strings = GetTokenizeStringByComma(s);
    return GetTreeFromStringVec(strings);
}

