/*
*
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
* k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*
* You may not alter the values in the nodes, only nodes itself may be changed.

* Only constant memory is allowed.

* For example,
* Given this linked list: 1->2->3->4->5

* For k = 2, you should return: 2->1->4->3->5

* For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1){
        	return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        ListNode* prev = &dummy;

        while(p){
        	prev = p;
        	for(int i=0; i < k; i++){
        		p = p->next;
        		if(!p){
        			return dummy.next;
        		}
        	}

        	p = reverse(prev, p->next);
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* start, ListNode* end)
    {
    	ListNode* p = start->next;
    	
    	while(p->next!= end)
    	{
    		ListNode* temp = p->next;
    		p->next = temp->next;
    		temp->next = start->next;
    		start->next = temp;
    	}

    	return p;
    }

    
};