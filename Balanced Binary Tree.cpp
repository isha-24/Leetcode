//https://leetcode.com/problems/balanced-binary-tree/

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
    bool b;
    int helper(TreeNode* root){
        if(!root) return 0;
        int hl=helper(root->left)+1;
        int hr=helper(root->right)+1;
        b = b && (abs(hl-hr)<=1);
        return max(hl,hr);
    }
    bool isBalanced(TreeNode* root) {
        // if(!root) return false;
        b=true;
        helper(root);
        return b;
    }
};
