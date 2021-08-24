//https://leetcode.com/problems/sum-of-left-leaves/

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
    void helper(TreeNode* root, int &sum){
        if(!root) return;
        if(!root->left && !root->right)
            sum+=root->val;
        helper(root->left, sum);
        if(root->right && (root->right->left || root->right->right))
            helper(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(!root->left && !root->right) return 0;
        helper(root, sum);
        return sum;
    }
};
