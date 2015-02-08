/*
Given an integer array with no duplicates. A max tree building on this array is defined as follow:
The root is the maximum number in the array
The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array.

input: [2, 5, 6, 0, 3, 1]
output:
        6
       / \
      5   3
     /   / \
    2   0   1
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v):val(v), left(NULL), right(NULL){};
};

class Solution{
public:
    TreeNode* maxTree(vector<int> A) {
        stack<TreeNode*> sta;
        for (int i = 0; i < A.size(); i++) {
            TreeNode* cur = new TreeNode(A[i]);
            while (!sta.empty() && sta.top()->val < cur->val) {
                sta.top()->right = cur->left;
                cur->left = sta.top();
                sta.pop();
            }
            sta.push(cur);
        }
        TreeNode* root = NULL;
        while (!sta.empty()) {
            sta.top()->right = root;
            root = sta.top();
            sta.pop();
        }
        return root;
    }
};
