//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l=1; int mxs=root->val;
        int currl=0;
        while(!q.empty()){
            int n=q.size();
            int sum=0; currl++;
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop(); sum+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(sum>mxs){
                mxs=sum;
                l=currl;
            }
        }
        return l;
    }
};
