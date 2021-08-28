#include "Header.h"

// 23. Merge k Sorted Lists
// Level : Hard
// 
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.
// 
// 
// Example 1:
// 
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:
// 
// Input: lists = []
// Output: []
// Example 3:
// 
// Input: lists = [[]]
// Output: []

#define PAIR pair<ListNode*, int>
class mycomp
{
    public:
    mycomp(){}

    bool operator() (const PAIR& lhs, const PAIR& rhs) const { return (lhs.first->val > rhs.first->val);}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<PAIR, vector<PAIR>, mycomp> PQ;
    int len = lists.size();
    for (int i = 0; i < len; ++i)
    {
        if (lists[i]) PQ.push(PAIR(lists[i], i));
    }

    PAIR top;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* temp = nullptr;
    while(!PQ.empty())
    {
        top = PQ.top();
        if (!tail)
        {
            tail = head = top.first;
        }
        else
        {
            tail->next = top.first;
            tail = tail->next;
        }

        temp = lists[top.second];
        if (temp->next)
        {
            lists[top.second] = temp->next;
            PQ.push(PAIR(lists[top.second], top.second));
        }
        PQ.pop();
    }

    return head;
}
