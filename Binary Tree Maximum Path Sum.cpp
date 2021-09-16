//https://leetcode.com/problems/binary-tree-maximum-path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int &mx){
        if(!root) return 0;
        int l=helper(root->left, mx);
        int r=helper(root->right, mx);
        mx=max(max(mx,root->val),max(root->val+l+r,max(root->val+l,root->val+r)));
        int m=max(root->val,max(root->val+l,root->val+r));
        return m;
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        helper(root, mx);
        return mx;
    }
};
