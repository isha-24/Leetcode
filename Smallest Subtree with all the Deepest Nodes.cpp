//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    int helper(TreeNode* root, int d, TreeNode* &ans, int &md){
        if(!root) {
            md=max(md,d);
            return d;
        }
        int l=helper(root->left, d+1, ans, md);
        int r=helper(root->right, d+1, ans, md);
        if(l==md && r==md) ans=root;
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int md=0; TreeNode* ans=NULL;
        helper(root, 0, ans, md);
        return ans;
    }
};
