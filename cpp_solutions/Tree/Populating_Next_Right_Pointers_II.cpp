/*
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would your previous solution still work?
*
**/
void connect(TreeLinkNode *root) {
	if(!root) return;

	TreeLinkNode* ptr = root;
	TreeLinkNode* next = NULL;
	TreeLinkNode* prev = NULL;

	while(ptr){
		if(!next){
			if(ptr->left)
				next = ptr->left;
			else if(ptr->right)
				next = ptr->right;
		}

		if(ptr->left){
			if(prev){
				prev->next = ptr->left;
			}
			prev = ptr ->left;
		}

		if(ptr->right){
			if(prev){
				prev->next = ptr->right;
			}
			prev = ptr->right;
		}

		if(ptr->next){
			ptr = ptr->next;
		} else {
			ptr = next;
			prev = NULL;
			next = NULL;
		}
		
	}       
}