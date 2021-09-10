//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* helper(vector<int>& in,vector<int>& ps, unordered_map<int,int> &m, int l1, int h1, int l2, int h2){
        if(l2>h2) return NULL;
        TreeNode* root=new TreeNode(ps[h2]);
        if(l2==h2) return root;
        int t=m[ps[h2]]; int ln=t-l1;
        root->left=helper(in, ps, m, l1, t-1, l2, l2+ln-1);
        root->right=helper(in, ps, m, t+1, h1, l2+ln, h2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& ps) {
        unordered_map<int,int> m;
        for(int i=0;i<in.size();i++) m[in[i]]=i;
        return helper(in, ps, m, 0, in.size()-1, 0, ps.size()-1);
    }
};
