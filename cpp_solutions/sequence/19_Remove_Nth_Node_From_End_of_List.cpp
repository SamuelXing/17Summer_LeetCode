/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.



*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *tmp = res;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        while (head != NULL) {
            head = head->next;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return res->next;
    }
};