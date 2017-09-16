/*
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
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

// Notes: It's a SORTED List

class Solution {
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return NULL;

    	ListNode* ptr = head;
    	while(ptr && ptr->next){
    		if(ptr->val == ptr->next->val)
    		{
    			ptr->next = ptr->next->next;
    		}
    		else{
    			ptr = ptr->next;
    		}
    		
    	}

    	return head;
    }
};
};