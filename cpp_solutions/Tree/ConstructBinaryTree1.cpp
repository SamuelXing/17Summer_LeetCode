/*
* Given preorder and inorder traversal 
* of a tree, construct the binary tree.
*
**/

typedef vector<int>::iterator Iter;
TreeNode* build(Iter pstart, Iter pend, Iter istart, Iter iend){
	if(istart == iend) return NULL;
	
	int nodeval = *pstart;
	TreeNode* newroot = new TreeNode(nodeval);
	
	Iter iterroot = find(istart, iend, nodeval);

	newroot->left = build(pstart+1, pstart+(iterroot - istart) + 1, istart, iterroot);
	newroot->right = build(pstart+(iterroot - istart) + 1, pend, iterroot+1, iend);

	return newroot;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}
