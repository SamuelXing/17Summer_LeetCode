/*
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
* 
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
*
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
* Notes: same as Binary Tree Path.
*
*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
    	if(!root) return 0;
    	sumTraverse(root, sum, sums);
    	return calculate(sums);
    }

private:
	int sum = 0;
	vector<int> sums;
	void sumTraverse(TreeNode* node, int sum, vector<int>& sums)
	{
		sum = sum*10 + node->val;
		if(node->left == NULL && node->right = NULL)
		{
			sums.push_back(sum);
		}
		else{
			if(node->left){
				sumTraverse(node->left, sum, sums);

			}
			if(node->right){
				sumTraverse(node->right, sum, sums);
			}
		}

	}

	int calculate(const vector<int>& sums)
	{
		int total = 0;
		for(int i=0; i< sums.size(); i++)
		{
			total += sums[i];
		}
		return total;
	}

};

