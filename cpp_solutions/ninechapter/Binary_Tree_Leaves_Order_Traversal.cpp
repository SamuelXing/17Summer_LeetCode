/*
    Given a binary tree, 
	collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
	
	Example
	Given binary tree:

          1
         / \
        2   3
       / \     
      4   5    
	Returns [[4, 5, 3], [2], [1]].
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
	int getHeight(TreeNode* node){
		if(!node) return 0;

		int d = max(getHeight(node->left), getHeight(node->right))+1;
		max_depth = max(max_depth, d);
		depth[d].push_back(node->val);
		return d;
	}
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        vector<vector<int>> rst;
        if(!root) return rst;

        getHeight(root);

        for(int i=1; i<= max_depth; i++){
        	rst.push_back(depth[i]);
        }
        return rst;
    }
private:
	int max_depth = 0;
	unordered_map<int, vector<int>> depth;
};



