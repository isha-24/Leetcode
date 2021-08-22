//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    unordered_set<int> s;
    void helper(TreeNode* root, vector<int> &v){
        if(!root) return;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        helper(root, v);
        int l=0;
        int r=v.size()-1;
        while(l<r){
            int t=v[l]+v[r];
            if(t==k) return true;
            if(t<k) l++;
            else r--;
        }
        return false;
    }
};
