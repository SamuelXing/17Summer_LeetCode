/*
* Two elements of a binary search tree (BST) are swapped by mistake.
*
* Recover the tree without changing its structure.
*
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
    	traverse(root);
    	int temp = firstElement->val;
    	firstElement->val = secondElement->val;
    	secondElement->val = temp;
    }

private:
	void traverse(TreeNode* root){
		if(root == NULL) return;

		traverse(root->left);
		if(firstElement == NULL && root->val < lastElement->val)
			firstElement = lastElement;
		if(firstElement != NULL && root->val < lastElement->val)
			secondElement = root;
		lastElement = root;
		traverse(root->right);
	}

	TreeNode* firstElement = NULL;
	TreeNode* secondElement = NULL;
	TreeNode* lastElement = new TreeNode(numeric_limits<int>::min());
};