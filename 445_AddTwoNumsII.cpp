#include "Header.h"

#if 0
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
#endif

ListNode* reverse(ListNode* head)
{
    if (!head) return nullptr;

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(head)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* rev_l1 = reverse(l1);
    ListNode* rev_l2 = reverse(l2);

    int carry = 0;
    int num;
    ListNode* head = nullptr;
    while (rev_l1 || rev_l2)
    {
        num = 0;
        if (rev_l1)
        {
            num += rev_l1->val;
            rev_l1 = rev_l1->next;
        }

        if (rev_l2)
        {
            num += rev_l2->val;
            rev_l2 = rev_l2->next;
        }


        num += carry;
        carry = num/10;
        num = num % 10;
        head = new ListNode(num %10, head);
    }

    if (carry != 0)
        head = new ListNode(carry, head);
    return head;
}

#if 0
Overview
Prerequisites

The problem is a combination of three basic problems:

Reverse Linked List.

Add Strings - the good problem to refresh textbook digit-by-digit addition algorithm.

Add Two Numbers - the same problem as the current one, but the digits are stored in reverse order.

Time and Space Complexity To Target

Each list should be parsed at least once, hence the best time complexity we could have is \mathcal{O}(N_1 + N_2)O(N
1
​
 +N
2
​
 ), where N_1N
1
​
  and N_2N
2
​
  are the numbers of elements in the lists.

Space complexity is more interesting. It's relatively standard for linked list problems not to allocate any data structure but the output list. This way, one could target \mathcal{O}(1)O(1) space complexity without taking the output list into account.

How to Solve: Reverse Input vs. Reverse Output

The standard textbook addition algorithm begins by summing the least-significant digits. Each digit is in the range from 0 to 9, and the "overflows" are managed by moving the carry into the next range.

img Figure 1. Textbook Addition.

That is quite convenient for the problem Add Two Numbers, where the digits are stored in reverse order. In this problem, the digits are stored in direct order. There are two ways to proceed:

Approach 1. The idea is to adapt input by reversing the input lists. This way, one could parse reverse lists starting from the head and use the textbook addition algorithm.
img Figure 2. Approach 1: Reverse Input + Construct Output by Adding to Front.

Approach 2. The idea is to adapt the addition algorithm.
img Figure 3. Approach 2: Adapt Addition Algorithm + Reverse Output.



Approach 1: Reverse Input + Construct Output by Adding to Front
img Figure 4. Reverse Input + Construct Output by Adding to Front.

Algorithm

Implement reverseList function.

Reverse both input lists: l1 = reverseList(l1), l2 = reverseList(l2).

Initialize the result list: head = None.

Initialize the carry: carry = 0.

Loop through lists l1 and l2 until you reach both ends.

Set x1 = l1.val if l1 is not finished yet, and x1 = 0 otherwise.

Set x2 = l2.val if l2 is not finished yet, and x2 = 0 otherwise.

Compute the current value: val = (carry + x1 + x2) % 10, and the current carry: carry = (carry + x1 + x2) / 10.

Update the result by adding the current value to front.

Move to the next elements in the lists.

If the carry is not equal to zero, append it to frond of the result list.

Return the result list: return head.

Implementation


Complexity Analysis

Time complexity: \mathcal{O}(N_1 + N_2)O(N
1
​
 +N
2
​
 ), where N_1 + N_2N
1
​
 +N
2
​
  is a number of elements in both lists.

Space complexity: \mathcal{O}(1)O(1) space complexity without taking the output list into account, and \mathcal{O}(\max(N_1, N_2))O(max(N
1
​
 ,N
2
​
 )) to store the output list.


Approach 2: Follow Up: Do not Reverse Input.
img Figure 5. Adapt Addition Algorithm + Reverse Output.

Algorithm

Find the length of both lists: n1 and n2.

Parse both lists and sum the corresponding positions without taking carry into account, i.e. convert 3->3->3 + 7->7 into 3->10->10 and then into 10->10->3.

To sum the corresponding positions, do the following:

If n1 >= n2, add to the current value the value of the node from the first list, and decrease the number of elements to parse: n1 -= 1.

If n1 < n2, add to the current value the value of the node from the second list and decrease the number of elements to parse: n2 -= 1.

Update the result by adding the current value to the front.

Now it's time to take care about the carry, to limit each node value by 9, i.e. to convert 10->10->3 into 0->1->4 and then into 4->1->0:

Initialize the carry carry = 0.

Re-initialize the current list: curr1 = head and the output list: head = None.

Parse the current list curr1:

Normalize the current value to be less than 10: val = (curr1.val + carry) % 10, and keep the carry: carry = (curr1.val + carry) // 10.

Update the result by adding the current value to front.

Move to the next element in the list: curr1 = curr1.next.

If the carry is not equal to zero, append it to frond of the result list.

Return the result list: return head.

Implementation

#endif
