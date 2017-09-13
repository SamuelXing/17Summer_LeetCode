/*
* Given a binary tree and a sum, find all root-to-leaf paths 
* where each path's sum equals the given sum.
*
**/

 bool Sum(TreeNode* node, int sum, int target, vector<int> temp,
             vector<vector<int>>& rst){
	if(node == NULL)
		return false;
	temp.push_back(node->val);
	sum = sum + node->val;
	if(node->left == NULL && node->right == NULL)
	{
		if(sum == target){
            rst.push_back(temp);
			return true;
        }
		else
			return false;
	}

	bool left = Sum(node->left, sum, target, temp, rst);
	bool right = Sum(node->right, sum, target, temp, rst);

	return left || right;
}


vector<vector<int>> pathSum(TreeNode* root, int sum) {
      
    vector<vector<int>> rst;
    vector<int> temp;  
    if(root == NULL)
      return rst;
      
    if(Sum(root, 0, sum, temp, rst))
       return rst;
     
    return rst;
}