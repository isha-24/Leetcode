//https://leetcode.com/problems/path-sum/

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
    int tsum=0; int b=0;
    void check(TreeNode* root, int sum){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(sum+root->val==tsum)
                b=1;
            return;
        }
        sum+=root->val;
        check(root->left, sum);
        check(root->right, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        tsum=targetSum;
        check(root, 0);
        return b;
    }
};
