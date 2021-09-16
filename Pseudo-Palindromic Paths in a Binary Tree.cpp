//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    void helper(TreeNode* root, int a, int &ans){
        if(!root) return;
        a^=(1<<root->val);
        if(!root->left && !root->right){
            if((a&(a-1))==0) ans++;
            return;
        }
        helper(root->left, a, ans);
        helper(root->right, a, ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int a=0;
        int ans=0;
        helper(root, a, ans);
        return ans;
    }
};
