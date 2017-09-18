/*
* Sort a linked list in O(n log n) time using constant space complexity.
*
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// using merge sort

class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;

		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = NULL;

		ListNode* p1 = sortList(head);
		ListNode* p2 = sortList(fast);

		return merge(p1, p2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
    	if(!l1) return l2;
    	if(!l2) return l1;

    	ListNode dummy(0);
    	ListNode* p = &dummy;

    	while(l1 && l2){
    		if(l1->val < l2->val){
    			p->next = l1;
    			l1 = l1->next;
    		}
    		else{
    			p->next = l2;
    			l2 = l2->next;
    		}

    		p=p->next;
    	}

    	if(l1){
    		p->next = l1;
    	}else{
    		p->next = l2;
    	}

    	return dummy.next;
    }
};





