/*
*
* Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.
*
* If the given node has no in-order successor in the tree, return null.
*

Example
Given tree = [2,1] and node = 1:

  2
 /
1
return node 2.

Given tree = [2,1,3] and node = 2:

  2
 / \
1   3
return node 3.

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


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
    	if(!root || !p)
    		return NULL;
    	if(root->val <= p->val)
    		return inorderSuccessor(root->right, p);
    	else{
    		TreeNode* left = inorderSuccessor(root->left, p);
    		return (left!=NULL)? left : root;
    	}
    }
};






