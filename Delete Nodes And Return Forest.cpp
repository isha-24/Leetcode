//https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    void helper(TreeNode* root, vector<int>& to_delete, vector<TreeNode*> &v, unordered_set<int> s, TreeNode* r, int i){
        if(!root) return;
        if(!r && s.find(root->val)!=s.end()){
            v[i]=NULL;
            if(root->left) v.push_back(root->left);
            if(root->right) v.push_back(root->right);
            return;
        }
        if(s.find(root->val)!=s.end()){
            if(r && r->left==root) r->left=NULL;
            if(r && r->right==root) r->right=NULL;
            if(root->left) v.push_back(root->left);
            if(root->right) v.push_back(root->right);
            return;
        }
        helper(root->left, to_delete, v, s, root, i);
        helper(root->right, to_delete, v, s, root, i);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> v;
        unordered_set<int> s;
        for(int i:to_delete) s.insert(i);
        v.push_back(root);
        for(int i=0;i<v.size();i++){
            helper(v[i], to_delete, v, s, NULL, i);
        }
        vector<TreeNode*> ans;
        for(TreeNode* t:v) if(t) ans.push_back(t);
        return ans;
    }
};
