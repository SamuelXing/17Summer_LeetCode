/*
* Given a binary tree and a sum, 
* determine if the tree has a root-to-leaf path 
* such that adding up all the values along the path equals the given sum.
*
**/

 bool hasPathSum(TreeNode* root, int sum) {
 	if(root == NULL)
 	{
 		return false;
 	}

 	if(root->left == NULL && root->right == NULL)
 	{
 		return sum == root->val;
 	}
 	return hasPathSum(root->left, sum-root->val) || 
 		hasPathSum(root->right, sum-root->val);
}


/*

Solution 2:

bool Sum(TreeNode* root, int sum, int target)
{
	if(root == NULL) 
		return false;

	sum = sum + root->val;
	if(root->left == NULL && root->right == NULL){
		if(sum == target)
			return true;
		else
			return false;
	}

	bool left = Sum(root->left, sum, target);
	bool right = Sum(root->right, sum, target);

	return left || right;
}

bool hasPathSum(TreeNode* root, int sum) {
 	if(root == NULL)
 	{
 		return false;
 	}	
}

*/


