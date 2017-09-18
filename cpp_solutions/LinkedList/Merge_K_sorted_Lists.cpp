/*
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
**/
// Divide and Conquer, T = O(NlogN)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.empty()) return NULL;

       int n = lists.size();
       while(n>1){
       	int k = (n+1)/2;
       	for(int i=0; i< n/2; i++){
       		lists[i] = mergeTwoLists(lists[i], lists[i+k]);
       	}
       	n= k;
       }
       return lists[0];
    }

     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     	ListNode* dummy = new ListNode(0);
     	ListNode* tmp = dummy;
     	while(l1 != NULL && l2 != NULL){
     		if(l1->val < l2->val){
     			tmp->next = l1;
     			l1 = l1->next;
     		}
     		else{
     			tmp->next = l2;
     			l2 = l2->next;
     		}
     		tmp = tmp->next;
     	}
     	if(l1 != NULL) tmp->next = l1;
     	else tmp->next = l2;
     	return dummy->next;
     }
};