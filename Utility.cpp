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

ListNode* GetListFromVector(const vector<int>& v)
{
    ListNode* head = nullptr;
    for (int idx = v.size() - 1; idx >= 0; --idx)
    {
        head = new ListNode(v[idx], head);
    }
    return head;
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

TreeNode* GetTree(const string& s)
{
    vector<string> values = GetStringValues(s.substr(1,s.length() - 2));
    if (values.empty()) return nullptr;

    TreeNode* head = new TreeNode(std::stoi(values[0]));
    queue<TreeNode*> Q;
    Q.push(head);

    TreeNode* front;
    int idx = 1;
    while (!Q.empty())
    {
        front = Q.front();

        Q.pop();
    }

}
