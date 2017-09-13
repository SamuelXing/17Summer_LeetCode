/*
* Given a binary tree, return the postorder traversal of its nodes' values.
*
* Recursive solution is trivial, could you do it iteratively?
*
**/

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> rst;
	vector<TreeNode*> visited;

	TreeNode* ptr = root,*lastVisited = NULL;

	while(ptr || !visited.empty())
	{
		while(ptr)
		{
			visited.push_back(ptr);
			ptr = ptr->left;
		}
		ptr = visited.back();
		if(ptr->right == NULL || ptr->right == lastVisited){
			visited.pop_back();
			rst.push_back(ptr->val);
			lastVisited = ptr;
			ptr = NULL;
		}
		else
		{
			ptr = ptr->right;
		}
	}        
	return rst;
}