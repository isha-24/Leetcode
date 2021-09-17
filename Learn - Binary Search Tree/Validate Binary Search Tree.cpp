//https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root, TreeNode* mn=NULL, TreeNode* mx=NULL) {
        if(!root) return true;
        if((mn && root->val<=mn->val) || (mx && root->val>=mx->val)) return false;
        int l=isValidBST(root->left, mn, root);
        int r=isValidBST(root->right, root, mx);
        return r&&l;
    }
};
