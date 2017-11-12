/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

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
    ListNode* swapPairs(ListNode* head) {
        if(!head ||head->next==NULL) return head;
        ListNode* iter = new ListNode(0);
        iter->next = head;
        ListNode* pTHead = iter;
        
        while(iter->next && iter->next->next)
        {   
            ListNode* temp = iter->next;
            ListNode* next = iter->next->next->next;
            iter->next = iter->next->next;
            iter->next->next = temp;
            iter->next->next->next = next;
            iter = iter->next->next;
        }
        return pTHead->next;
    }
};