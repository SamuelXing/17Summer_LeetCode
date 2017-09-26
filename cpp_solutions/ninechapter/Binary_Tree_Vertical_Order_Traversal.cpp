/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.


Example
Given binary tree {3,9,20,#,#,15,7}

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
Return its vertical order traversal as:
[[9],[3,15],[20],[7]]

Given binary tree {3,9,8,4,0,1,7}

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
Return its vertical order traversal as:
[[4],[9],[3,0,1],[8],[7]]

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

// BFS + Data Structure

class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> ans;
        if(!root) return ans;

    	map<int, vector<int>> level2elements; // cannot use unordered_map
    	queue<pair<TreeNode*, int>> BFSQueue;

    	BFSQueue.push(make_pair(root, 0));
    	while(!BFSQueue.empty()){
    		pair<TreeNode*, int> current = BFSQueue.front(); BFSQueue.pop();
    		level2elements[current.second].push_back(current.first->val);

            if(current.first->left){
    			BFSQueue.push(make_pair(current.first->left, current.second-1));
    		}
    		
            if(current.first->right){
    			BFSQueue.push(make_pair(current.first->right, current.second+1));
    		}
    		
    	}

    	for(auto iter:level2elements){
    		ans.push_back(iter.second);
    	}
    	return ans;
    }
};






