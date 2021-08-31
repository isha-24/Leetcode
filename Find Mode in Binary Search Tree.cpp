//https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    void helper(TreeNode* root, vector<int> &v, int &prev, int &max, int &curr){
        if(!root) return;
        helper(root->left, v, prev, max, curr);
        if(root->val==prev){curr++;}
        else{curr=1; prev=root->val;}
        if(max<curr){
            v.clear();
            v.push_back(prev);
            max=curr;
        }
        else if(max==curr){
            v.push_back(prev);
        }
        prev=root->val;
        helper(root->right, v, prev, max, curr);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        int prev=100001;
        int max=0;
        int curr=0;
        helper(root, v, prev, max, curr);
        return v;
    }
};
