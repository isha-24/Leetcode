//https://leetcode.com/problems/balance-a-binary-search-tree/

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
    void helper(TreeNode* root, vector<int> &v){
        if(!root) return;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
    TreeNode* balanceTree(vector<int> &v, int l, int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=balanceTree(v, l, mid-1);
        root->right=balanceTree(v, mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return balanceTree(v, 0, v.size()-1);
    }
};
