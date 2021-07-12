//https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int findMaxDepth(TreeNode* root){
        if(!root)
            return 0;
        int l=findMaxDepth(root->left);
        int r=findMaxDepth(root->right);
        return max(l,r)+1;
    }
    
    int maxDepth(TreeNode* root) {
        int ans=findMaxDepth(root);
        return ans;
    }
};
