#include "Utility.h"

// 21. Merge Two Sorted Lists
// Level - Easy
// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
// 
// Example 1:
// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// 
// Example 2:
// Input: l1 = [], l2 = []
// Output: []
// 
// Example 3:
// Input: l1 = [], l2 = [0]
// Output: [0]
// 
// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        ListNode* start = nullptr;//(l1->val <= l2->val)? l1 : l2;
        ListNode* temp;
        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }

            if (head)
            {
                head->next = temp;
                head = head->next;
            }
            else start = head = temp;
        }

        head->next = (l1) ? l1 : l2;
        return start;
    }

void test_mergeTwoLists()
{
    vector<pair<string, string>> tc = {pair<string,string>("[1,2,4]", "[1,3,4]"),
                                       pair<string,string>("[]", "[]"),
                                       pair<string,string>("[]", "[0]"),
                                       pair<string,string>("[5]", "[1,2,4]")
                                      };
    vector<string> answers = {"[1,1,2,3,4,4]", "[]", "[0]", "[1,2,4,5]"};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (!CompareList(DeSerializeList(answers[i]), mergeTwoLists(DeSerializeList(tc[i].first), DeSerializeList(tc[i].second)))) ERROR_LOG;
    }
}
