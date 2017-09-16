
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, num.size());
}

TreeNode* build(vector<int>& num, int start, int end) {
    if(start >= end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    TreeNode* node = new TreeNode(num[mid]);
    node->left = build(num, start, mid);
    node->right = build(num, mid + 1, end);

    return node;
}