#include "Utility.h"

// 24. Swap Nodes in Pairs
// Level - Medium
// 
// Given a linked list, swap every two adjacent nodes and return its head.
// You may not modify the values in the list's nodes. Only nodes itself may be changed.
// 
// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// 
// Example 2:
// Input: head = []
// Output: []
// 
// Example 3:
// Input: head = [1]
// Output: [1]
// 
// Constraints:
// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

ListNode* swapPairs(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return head;

    ListNode* start = head;
    head = head->next;
    ListNode* last = nullptr;

    for(; start && start->next; start = start->next)
    {
        if (last)
        {
            last->next = start->next;
        }

        ListNode* temp = start->next->next;
        start->next->next = start;
        start->next = temp;
        last = start;
    }

    return head;
}

void test_swapPairs()
{
    vector<string> tc = {"[1,2,3,4]", "[]", "[1]", "[1,2,3]"};
    vector<string> answers = {"[2,1,4,3]", "[]", "[1]", "[2,1,3]"};

    for (unsigned int i = 0; i < tc.size(); ++i)
    {
        ListNode* t = swapPairs(DeSerializeList(tc[i]));
        ListNode* a = DeSerializeList(answers[i]);
        if (!CompareList(t, a)) ERROR_LOG;
    }
}
