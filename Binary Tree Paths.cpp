//https://leetcode.com/problems/binary-tree-paths/

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
    void helper(TreeNode* root, vector<string> &s, string str){
        if(!root) return;
        if(!root->left && !root->right){
            if (str=="") str=to_string(root->val);
            else str+="->"+to_string(root->val);
            s.push_back(str);
            return;
        }
        if (str=="") str=to_string(root->val);
        else str+="->"+to_string(root->val);
        helper(root->left, s, str);
        helper(root->right, s, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        vector<string> s;
        helper(root, s, str);
        return s;
    }
};
