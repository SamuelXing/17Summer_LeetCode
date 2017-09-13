/*
* Given a binary tree, return the preorder traversal of its nodes' values.
* Recursive solution is trivial, could you do it iteratively?
* 
**/

/*
* Soution #1
*/
vector<int> preorder;

void traverse(TreeNode* root)
{
	if(root == NULL)
		return;
	preorder.push_back(root->val);
	traverse(root->left);
	traverse(root->right);
}

vector<int> preorderTraversal(TreeNode* root)
{
	preorder.clear();
	traverse(root);
	return preorder;
}

// solution #2 - Stack Solution

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> vals;
	if(root == NULL) {
		return vals;
	}

	vector<TreeNode*> nodes;
	nodes.push_back(root);

	while(!nodes.empty())
	{
		TreeNode* top = nodes.back();
		vals.push_back(top->val);

		// accessed this node, pop back
		nodes.pop_back();

		if(top->right){
			nodes.push_back(top->right);
		}
		if(top->left){
			nodes.push_back(top->left);
		}
	}

	return vals;
}
