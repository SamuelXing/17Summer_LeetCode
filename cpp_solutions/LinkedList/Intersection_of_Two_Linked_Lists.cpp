/*
* Write a program to find the node at which the intersection of two singly linked lists begins.
*
*
* Notes:
* If the two linked lists have no intersection at all, return null.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// My Note: converting this problem to find Linked_List_Cycle, thinking how

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        // get last node of List A
        ListNode* ptr = headA;
        while(ptr->next){
        	ptr = ptr->next;
        }
        ptr->next = headB;

        ListNode* slow = headA;
        ListNode* fast = headB;
        while(fast->next && fast->next->next)
        {
        	slow = slow->next;
        	fast = fast->next->next;

        	if(slow == fast){
        		slow = headA;
        		while(slow != fast){
        			slow = slow->next;
        			fast = fast->next;
        		}
        		ptr->next = NULL;
        		return slow;
        	}
        }

        ptr->next = NULL;
        return NULL;

    }
};