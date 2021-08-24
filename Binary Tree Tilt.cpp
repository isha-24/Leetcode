//https://leetcode.com/problems/binary-tree-tilt/

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
    int helper(TreeNode* root, int& t){
        if(!root) return 0;
        int l=helper(root->left, t);
        int r=helper(root->right, t);
        t+=abs(l-r);
        return root->val + l + r;
    }
    int findTilt(TreeNode* root) {
        int t=0;
        int temp=helper(root, t);
        return t;
    }
};
