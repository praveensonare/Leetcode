#include "Header.h"

// 19. Remove Nth Node From End of List
// Level : Medium
// 
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Follow up: Could you do this in one pass?
// 
// Example 1:
//  1->2->3->4->5
//  1->2->3->5
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// 
// 
// Example 2:
// Input: head = [1], n = 1
// Output: []
// 
// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* delNode = head;
    ListNode* start = head;

    for (int i = 1; i <= n; ++i) start = start->next; 

    if (!start) return head->next;

    delNode = head;
    for ( ; start->next; start = start->next, delNode = delNode->next);

    auto temp = delNode->next;
    delNode->next = delNode->next->next;
    delete temp;

    return head;
}
