/*
* Given inorder and postorder traversal of a tree, construct the binary tree.
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

typedef vector<int>::iterator Iter;

TreeNode* build(Iter istart, Iter iend, Iter pstart, Iter pend)
{
	if(istart==iend==NULL){
		return NULL;
	}

	int nodevalue = *(pend-1);
	Iter rootIter = find(istart, iend, nodevalue);
	TreeNode* root = new TreeNode(nodevalue);

	root->left = build(istart, rootIter, pstart, pstart+(rootIter-istart));
	root->right = build(rootIter+1, iend, pstart+(rootIter-istart), pend-1);

	return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}