/*
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,

* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

* You must do this in-place without altering the nodes' values.

* For example,

* Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
   		
   		// Split this list to two parts
   		ListNode* slow = head;
   		ListNode* fast = head;

   		while(fast->next && fast->next->next){
   			slow = slow->next;
   			fast = fast->next->next;
   		}     

   		fast = slow->next;
   		slow->next = NULL;

   		// reverse right part;
   		ListNode* dummy = new ListNode(0);
   		while(fast){
   			ListNode* n = dummy->next;
   			dummy->next = fast;
   			ListNode* nn = fast->next;
   			fast->next = n;
   			fast = nn;
   		}

   		slow = head;
   		fast = dummy->next;

   		// merge
   		while(slow){
   			if(fast != NULL){
   				ListNode* n = slow->next;
   				slow->next = fast;
   				ListNode* nn = fast->next;
   				fast->next = n;
   				fast = nn;
   				slow = n;
   			} else{
   				break;
   			}
   		}
    }
};     
