//https://leetcode.com/problems/subtree-of-another-tree/

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
    bool check(TreeNode* root, TreeNode* subRoot){
        if(!root || !subRoot) return root==subRoot;
        return root->val==subRoot->val && 
            check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
    void helper(TreeNode* root, TreeNode* subRoot, bool &b){
        if(!root) return;
        if(root->val==subRoot->val) b=b||check(root, subRoot);
        if(!b)
            helper(root->left, subRoot, b);
        if(!b)
            helper(root->right, subRoot, b);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool b=false;
        helper(root, subRoot, b);
        return b;
    }
};
