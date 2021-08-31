//https://leetcode.com/problems/diameter-of-binary-tree/

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
    int m=INT_MIN;
    int helper(TreeNode* root) {
        if(!root) return -1;
        int hl=helper(root->left)+1;
        int hr=helper(root->right)+1;
        m=max(m, hl+hr);
        return max(hl,hr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return m;
    }
};
