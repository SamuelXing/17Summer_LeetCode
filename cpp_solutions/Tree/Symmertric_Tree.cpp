/*
* Given a binary tree, check whether it is a mirror of itself 
* (ie, symmetric around its center).
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
bool equal(TreeNode* left, TreeNode* right)
{
	if(left == NULL && right == NULL){
		return true;
	}
	if(left == NULL || right == NULL){
		return false;
	}
	if(left->val != right->val){
		return false;
	}
	return equal(left->left, right->right)&&equal(left->right,right->left);
}

bool isSymmetric(TreeNode* root) {
	if(root == NULL)
		return true;
	return equal(root->left, root->right);
}
