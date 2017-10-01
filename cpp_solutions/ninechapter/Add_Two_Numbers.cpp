/*
	You have two numbers represented by a linked list, 
	where each node contains a single digit. 
	The digits are stored in reverse order, 
	such that the 1's digit is at the head of the list. 
	Write a function that adds the two numbers and returns the sum as a linked list.

Example
Given 7->1->6 + 5->9->2. That is, 617 + 295.

Return 2->1->9. That is 912.

Given 3->1->5 and 5->9->2, return 8->0->8.

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
    /*
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode* addLists(ListNode * l1, ListNode * l2) {

    	if(!l1) return l2;
    	if(!l2) return l1;

        // write your code here
        int carry = 0; 
        ListNode* it, *itt;
        it = l1;
       	itt = l2;
       	ListNode* dummy = new ListNode();
       	ListNode* p = dummy;
       	while(it || itt){
       		if(it){
       			carry += it->val;
       			it = it->next;
       		}
       		if(itt){
       			carry += itt->val;
       			itt = itt->next;
       		}
       		p->next = new ListNode(carry%10);
       		p = p->next;
       		carry /= 10;
       	}
       	if(carry){
       		p->next = new ListNode(carry);
       	}
       	return dummy->next;
    }
};
