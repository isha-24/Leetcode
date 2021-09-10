//https://leetcode.com/problems/path-sum/

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
    bool helper(TreeNode* root, int ts, int sum){
        if(!root) return false;
        if(!root->left && !root->right) return (ts==sum+root->val);
        bool l=helper(root->left, ts, sum+root->val);
        bool r=helper(root->right, ts, sum+root->val);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int ts) {
        return helper(root, ts, 0);
    }
};
