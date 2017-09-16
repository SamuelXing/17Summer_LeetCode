/*
* Given a binary tree, return all root-to-leaf paths.
*
**/

/*
For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]	
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
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<int> path;
    	vector<string> rst;
    	if(!root) return rst;
    	traverse(root, path, rst);
    	return rst;    
    }

private:
    void traverse(TreeNode* node, vector<int>& path, vector<string>& rst)
    {
    	if (!node) return;
    	path.push_back(node->val);

    	if(node->left == NULL && node->right == NULL)
    	{
    		rst.push_back(convert(path));
    	}
    	else{
    		if(node->left){
    			traverse(node->left, path, rst);
    			path.pop_back();
    		}
    		if(node->right){
    			traverse(node->right, path, rst);
    			path.pop_back();
    		}
    	}

    }

    string convert(vector<int> path){
    	stringstream ss;
    	int i;
    	for(i=0; i<path.size()-1; i++) ss<< path[i] << "->";
    	ss << path[i];
    	return ss.str();
    }

};