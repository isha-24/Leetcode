//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    TreeNode* helper(vector<int>& pr, vector<int>& ps, unordered_map<int, int> m, int a, int b, int c, int d){
        TreeNode* root=new TreeNode(pr[a]);
        if(a==b) return root;
        int i=m[pr[a+1]];
        int l=i-c;
        root->left=helper(pr, ps, m, a+1, a+l+1, c, c+l);
        if(i+1==d) return root;
        root->right=helper(pr, ps, m, a+l+2, b, i+1, d-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pr, vector<int>& ps) {
        unordered_map<int, int> m;
        for(int i=0;i<ps.size();i++) m[ps[i]]=i;
        return helper(pr, ps, m, 0, pr.size()-1, 0, ps.size()-1);
    }
};
