//https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int i=INT_MAX, diff=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        while(!root) return INT_MAX;
        getMinimumDifference(root->left);
        diff=min(diff, abs(i-root->val));
        i=root->val;
        getMinimumDifference(root->right);
        return diff;
    }
};
