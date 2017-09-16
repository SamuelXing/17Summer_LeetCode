/*
* Given a linked list, determine if it has a cycle in it.
* 
**/

// Notes: slow and fast pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
        	slow = slow->next;
        	fast = fast->next->next;
        	if(fast == slow) return true;
        }
        return false;
    }
};