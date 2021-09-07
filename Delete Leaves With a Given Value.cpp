//https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    bool helper(TreeNode* root, int k){
        if(!root) return true;
        bool b1=helper(root->left, k);
        bool b2=helper(root->right, k);
        return (root->val==k) && b1 && b2;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        
        if(root->val==target){
            bool b=helper(root, target);
            if(b) return NULL;
        }
        
        if(root->left && root->left->val==target){
            bool b=helper(root->left, target);
            if(b) root->left=NULL;
        }
        if(root->right && root->right->val==target){
            bool b=helper(root->right, target);
            if(b) root->right=NULL;
        }
        
        removeLeafNodes(root->left, target);
        removeLeafNodes(root->right, target);
        return root;
    }
};
