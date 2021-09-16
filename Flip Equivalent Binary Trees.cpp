//https://leetcode.com/problems/flip-equivalent-binary-trees/

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        bool b1=false, b2=false;
        if(root1->val != root2->val) return false;
        b1=flipEquiv(root1->left, root2->left);
        if(b1) b1=b1&&flipEquiv(root1->right, root2->right);
        else {
            b2=flipEquiv(root1->left, root2->right);
            b2=b2&&flipEquiv(root1->right, root2->left);
        }
        return b1||b2;
    }
};
