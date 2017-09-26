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
    /*
     * @param root: the root of binary tree
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        // write your code here
    	sum = 0;
    	DFS(root);
    	return root;
    }

    void DFS(TreeNode* node){
    	if(!node) return;

    	DFS(node->right);
    	sum += node->val;
    	node->val = sum;
    	DFS(node->left);

    }
private: 
	int sum;
};