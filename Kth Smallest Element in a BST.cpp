//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int n=0, x=0;
    int kthSmallest(TreeNode* root, int k) {
        if(x==k) return n;
        if(!root) return 0;
        int l=kthSmallest(root->left, k);
        x++;
        if(k==x) n=root->val;
        int r=kthSmallest(root->right, k);
        return n;
    }
};
