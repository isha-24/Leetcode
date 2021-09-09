//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int dff=INT_MIN;
     void dfs(TreeNode* root, int sum, int res){
         if(!root) return ;
         sum=max(sum, root->val);
         res=min(res, root->val);
         dff=max(dff, sum-res);
         dfs(root->left, sum, res);
         dfs(root->right, sum, res);   
     }
    
    int maxAncestorDiff(TreeNode* root) {
        int sum=INT_MIN;
        int res=INT_MAX;
        dfs(root, sum, res);
        return dff;
    }
};
