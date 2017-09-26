/*
	Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, 
	flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

Example
Given a binary tree {1,2,3,4,5}

    1
   / \
  2   3
 / \
4   5

return the root of the binary tree {4,5,2,#,#,3,1}.

   4
  / \
 5   2
    / \
   3   1  

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
	void DFS(TreeNode* node){
		if(!node->left){
			newroot = node;
			return;
		}
		DFS(node->left);
		node->left->left = node->right;
		node->left->right = node;
		node->left = NULL;
		node->right = NULL;
	}

    /*
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        // write your code here
    	if(!root) return NULL;

    	DFS(root);
    	return newroot;
    }

private:
	TreeNode* newroot;

};




