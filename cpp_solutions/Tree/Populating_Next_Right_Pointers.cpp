/*
* Populate each next pointer to point to its next right node.
* If there is no next right node, the next pointer should be set to NULL.
*
**/

void connect(TreeLinkNode *root) {        
	if(!root){
		return;
	}

	TreeLinkNode* ptr = root;
	TreeLinkNode* first = NULL;

	while(ptr)
	{
		if(!first)
			first = ptr->left;
		// if node has left child
		if(ptr->left)
			ptr->left->next = ptr->right;
		else
			break;

		if(ptr->next)
		{
			ptr->right->next = ptr->next->left
			ptr = ptr->next;
			continue;
		}
		else
		{
			ptr = first;
			first = NULL;
		}
	}
}