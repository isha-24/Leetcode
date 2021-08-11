//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sum=0;
    void helper(TreeNode* root, int bn){
        if(!root) return;
        if(!root->left && !root->right){
            bn=(bn<<1) | root->val;
            sum+=bn; return;
        }
        bn=(bn<<1) | root->val;
        helper(root->left, bn);
        helper(root->right, bn);
    }
    int sumRootToLeaf(TreeNode* root) {
        int bn=0;
        helper(root, bn);
        return sum;
    }
};
