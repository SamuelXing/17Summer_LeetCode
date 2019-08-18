/*
* Given a singly linked list where elements are sorted in ascending order, 
* convert it to a height balanced BST.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Solution 1:
TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    int size = getListSize(head);
    return convertHelper(head, size);
}
    
int getListSize(ListNode *head) {
    int size = 0;
    while (head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}
    
TreeNode *convertHelper(ListNode *&head, int size) {
    if (size == 0) {
        return NULL;
    }
    
    TreeNode *root = new TreeNode(0);
    root->left = convertHelper(head, size / 2);
    root->val = head->val; head = head->next;
    root->right = convertHelper(head, size - size / 2 - 1);
    return root;
}

//Solution 2: slow and fast pointer
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
    	return sortedListToBST(head, NULL);
    }
    
private:
    TreeNode *sortedListToBST(ListNode *start, ListNode *end)
    {
    	if(start == end)
    		return NULL;
    	if(start->next == end)    // 
    	{	
    		TreeNode *root = new TreeNode(start->val);
    		return root;
    	}
    	ListNode *slow = start, *fast = start;
    	while( fast != end && fast->next != end )    
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	TreeNode *root = new TreeNode(slow->val);
    	root->left = sortedListToBST(start, slow);
    	root->right = sortedListToBST(slow->next, end);
    	return root;
    }
};
