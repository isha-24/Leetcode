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
    bool helper(TreeNode* root, TreeNode* mn, TreeNode* mx){
        if(!root) return true;
        if((mn!=nullptr && root->val<=mn->val) || (mx!=nullptr && root->val>=mx->val))
           return false;
        return (helper(root->left, mn, root) && helper(root->right, root, mx));
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
};
