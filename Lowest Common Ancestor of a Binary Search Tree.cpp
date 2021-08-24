//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* root, int v1, int v2, TreeNode* &r){
        if(!root){
            return;
        }
        if((root->val>=v1 && root->val<=v2) || (root->val<=v1 && root->val>=v2)){
            r=root;
            return;
        }
        if(root->val>=v1 && root->val>=v2)
            return helper(root->left, v1, v2, r);
        if(root->val<=v1 && root->val<=v2)
            return helper(root->right, v1, v2, r);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1=p->val; int v2=q->val;
        TreeNode* r=NULL;
        helper(root, v1, v2, r);
        return r;
    }
};
