#include "Utility.h"

// 369. Plus One Linked List
// Level - Medium
// 
// Given a non-negative integer represented as a linked list of digits, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list.
// 
// Example 1:
// Input: head = [1,2,3]
// Output: [1,2,4]
// 
// Example 2:
// Input: head = [0]
// Output: [1]
// 
// Constraints:
// The number of nodes in the linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// The number represented by the linked list does not contain leading zeros except for the zero itself.

ListNode* plusOne(ListNode* head) {
    ListNode* lastNotNine = nullptr;

    for (ListNode* start = head; start; start = start->next)
    {
        if (start->val < 9) lastNotNine = start;
    }

    if (!lastNotNine)
    {
        for (ListNode* start = head; start; start = start->next) start->val = 0;
        head = new ListNode(1, head);
    }
    else ++lastNotNine->val;

    return head;
}

void test_plusOne()
{
    vector<string> tc = {"[1,2,3]", "[0]","[9,9,9]"};
    vector<string> answers = {"[1,2,4]", "[1]", "[1,0,0,0]"};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (!CompareList(plusOne(DeSerializeList(tc[i])), DeSerializeList(answers[i]))) ERROR_LOG;
    }
}
