//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

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
    TreeNode* getTargetCopy(TreeNode* org, TreeNode* cln, TreeNode* target) {
        if(!org) return NULL;
        if(org==target) return cln;
        TreeNode* l= getTargetCopy(org->left, cln->left, target);
        TreeNode* r= getTargetCopy(org->right, cln->right, target);
        return (l?l:r);
    }
};
