/*
* Given a binary tree, determine if it is height-balanced.
*
*/

int depth(TreeNode* root)
{
	if(root == NULL) return 0;

	int left = depth(root->left);
	int right = depth(root->right);

	if(left == -1 || right == -1 || abs(left - right) > 1){
		return -1;
	}
	return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {        
	return depth(root) != -1;
}
