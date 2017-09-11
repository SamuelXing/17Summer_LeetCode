//Given a binary tree, find its minimum depth.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solve_dp(TreeNode* node){
	if(node == NULL) return 0;

	if(node->left == NULL && node->right == NULL){
		return 1;
	}

	int left = right = 0x7fffffff;

	if(node->left)
		left = solve_dp(node->left);
	if(node->right)
		right = solve_dp(node->right);

	return min(left, right) + 1;
}

int minDepth(TreeNode *root) {
	if(!root) return 0;

	return solve_dp(root);
}