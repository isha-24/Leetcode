//https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int helper(TreeNode* root, int x, int &count){
        if(!root) return count;
        bool b=true;
        if(root->val<x) b=false;
        if(b) count++;
        x=max(root->val, x);
        helper(root->left, x, count);
        helper(root->right, x, count);
        return count;
        
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        return helper(root, INT_MIN, count);
    }
};
