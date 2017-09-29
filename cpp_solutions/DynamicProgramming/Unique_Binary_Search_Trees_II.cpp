/*

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    vector<TreeNode*> generateTrees(int n) {
         // write your code here
        vector<TreeNode*> rst;
        if(n == 0){
            return rst;
        }
        rst = generate(0,n-1);
        return rst;
    }
private:
	vector<TreeNode*> generate(int begin, int end){
		vector<TreeNode*> ret;
		if(begin > end){
			ret.push_back(NULL);
			return ret;
		}

		for(int i=begin; i<=end; i++){
			vector<TreeNode*> leftTree = generate(begin, i-1);
			vector<TreeNode*> rightTree = generate(i+1, end);
			for(int j =0; j < leftTree.size(); j++){
				for(int k=0; k < rightTree.size(); k++){
					TreeNode* node = new TreeNode(i+1);
					ret.push_back(node);
					node->left = leftTree[j];
					node->right = rightTree[k];
				}
			}
		}

		return ret;
	}
};