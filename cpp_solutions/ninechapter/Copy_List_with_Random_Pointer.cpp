/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        RandomListNode* dummyHead = new RandomListNode(0);
        RandomListNode* it = dummyHead;
        RandomListNode* p = head;
        while(p){
        	RandomListNode* node = new RandomListNode(p->label);
        	old2new[p] = node;
        	it->next = node;
        	it = it->next;
        	p = p->next;
        }

        p = head;
        while(p){
        	if(p->random){
        		old2new[p]->random = old2new[p->random];
        	}
        	p=p->next;
        }
        return dummyHead->next;
    }
};