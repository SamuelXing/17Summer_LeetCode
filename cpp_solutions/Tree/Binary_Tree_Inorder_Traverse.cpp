/*
* Given a binary tree, return the inorder traversal of its nodes' values.
*
*/

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> rst;
	if(root == NULL) return rst;

	vector<TreeNode*> visited;

	while(root || !visited.empty())
	{
		while(root)
		{
			visited.push_back(root);
			root = root->left;
		}

		root = visited.back();
		rst.push_back(root->val);
		visited.pop_back();
		root = root->right;
	
	}

	return rst;
}