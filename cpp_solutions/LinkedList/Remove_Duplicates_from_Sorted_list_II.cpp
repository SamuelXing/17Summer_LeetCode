/*
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
*
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
*
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *root = NULL;
        ListNode **ppNext = &root;
        while(head) {
            if(head->next == NULL || head->next->val != head->val) {
                *ppNext = head;
                ppNext = &(head->next);
                head = head->next;
            } else {
                int val = head->val;
                do {
                    head = head->next;
                } while(head != NULL && head->val == val);
            }
        }
        *ppNext = NULL;
        return root;
    }
};