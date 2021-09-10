//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* helper(vector<int>& pr, vector<int>& in, unordered_map<int,int> &m, int start, int end, int &idx){
        if(start>end) return NULL;
        int val=pr[idx++];
        TreeNode* root=new TreeNode(val);
        if(start==end) return root;
        root->left=helper(pr, in, m, start, m[val]-1, idx);
        root->right=helper(pr, in, m, m[val]+1, end, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        unordered_map<int,int> m; int idx=0;
        for(int i=0;i<in.size();i++) m[in[i]]=i;
        return helper(pr, in, m, 0, pr.size()-1, idx);
    }
};
