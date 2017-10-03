/*
Given a binary tree, 
find the subtree with maximum sum. 
Return the root of the subtree.


Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   3 -4  -5 
return the node with value 3.

*/

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        dfs(root);
        return rst;
    }
private:
	TreeNode* rst = nullptr;
	int maxSum = INT_MIN;

	int dfs(TreeNode* node){
		if(!node) return 0;

		int leftSum = dfs(node->left);
		int rightSum = dfs(node->right);

		if(!rst || node->val + leftSum + rightSum > maxSum ){
			rst = node;
			maxSum = node->val + leftSum + rightSum;
		}
		return node->val + leftSum + rightSum;
	}

};