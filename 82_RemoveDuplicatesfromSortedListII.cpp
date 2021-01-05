#include "Utility.h"

// 82. Remove Duplicates from Sorted List II
// Level - Medium
// 
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
// 
// Example 1:
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// 
// Example 2:
// Input: head = [1,1,1,2,3]
// Output: [2,3]
// 
// Constraints:
// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* start = new ListNode(0, head);
    ListNode* prev = start;

    for (; head; head = head->next)
    {
        if (head->next && head->next->val == head->val)
        {
            while(head->next && head->next->val == head->val) head = head->next;
            prev->next = head->next;
        }
        else prev = prev->next;
    }

    return start->next;
}

void test_deleteDuplicates()
{
    VS tc = {"[1,2,3,3,4,4,5]", "[1,1,1,2,3]", "[1,1,2]", "[1,1]", "[1,1,2,2]"};
    VS answers = {"[1,2,5]", "[2,3]", "[2]", "[]","[]"};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (!CompareList(deleteDuplicates(DeSerializeList(tc[i])), DeSerializeList(answers[i]))) ERROR_LOG;
    }
}
