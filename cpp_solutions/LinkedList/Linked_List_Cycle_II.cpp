/*
* Given a linked list, return the node where the cycle begins. 
* If there is no cycle, return null.
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
// also slow and fast pointer
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head && !head->next)
        	return false;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
        	slow = slow->next;
        	fast = fast->next->next;
        	if(slow == fast){
        		slow = head;
        		while(slow != fast){
        			fast = fast->next;
        			slow = slow->next;
        		}
        		return slow;
        	}
        }

        return NULL;
    }
};