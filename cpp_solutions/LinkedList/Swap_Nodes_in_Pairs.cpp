/*
*
* Given a linked list, swap every two adjacent nodes and return its head.

* For example, Given 1->2->3->4, you should return the list as 2->1->4->3.

* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
		if(!head || !head->next) return head;

		ListNode dummy(0);
		ListNode* p = &dummy;
		dummy.next = head;

		while(p && p->next && p->next->next){
			ListNode* n = p->next;
			ListNode* nn = p->next->next;
			p->next = nn;
			n->next = nn->next;
			nn->next = n;
			p = p->next->next;
		}        

		return dummy.next;
    }
};