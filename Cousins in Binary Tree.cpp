//https://leetcode.com/problems/cousins-in-binary-tree/

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
    void helper(TreeNode* root, int h, int n, int &hh, TreeNode* prev, TreeNode* &r){
        if(!root) return;
        if(root->val==n) { hh=h; r=prev; return;}
        h=h+1;
        helper(root->left, h, n, hh, root, r);
        helper(root->right, h, n, hh, root, r);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int a=0; TreeNode* ar=NULL, *br=NULL;
        helper(root, 0, x, a, NULL, ar);
        int b=0;
        helper(root, 0, y, b, NULL, br);
        return (a==b && ar!=br);
    }
};
