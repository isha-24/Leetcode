//https://leetcode.com/problems/delete-node-in-a-bst/

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
    void helper(TreeNode* root, int key, TreeNode* prev){
        if(!root) return;
        if(root->val==key) {
            if(!root->right) {
                if(prev->left==root) prev->left=root->left;
                else prev->right=root->left;
            }
            else {
                if(prev->left==root) prev->left=root->right;
                else prev->right=root->right;
                TreeNode* t=root->right;
                if(root->left){
                    while(t->left) t=t->left;
                    t->left=root->left;
                }
            }
        }
        else if(root->val>key) helper(root->left, key, root);
        else helper(root->right, key, root);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy=new TreeNode(INT_MIN);
        dummy->left=root;
        helper(root, key, dummy);
        return dummy->left;
    }
};
