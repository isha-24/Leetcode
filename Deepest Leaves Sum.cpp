//https://leetcode.com/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        int n; int sum;
        q.push(root);
        while(!q.empty()){
            sum=0; n=q.size();
            for(int i=0; i<n; i++){
                TreeNode* t=q.front();
                q.pop(); sum+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return sum;
    }
};
