//https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        deque<TreeNode*> dq;
        for(int a : nums){
            TreeNode* t=new TreeNode(a);
            if(!dq.empty() && dq.back()->val<t->val){
                while(!dq.empty() && dq.back()->val<t->val){
                    t->left=dq.back();
                    dq.pop_back();
                }
            }
            if(!dq.empty() && dq.back()->val>t->val){
                dq.back()->right=t;
            }
            dq.push_back(t);
        }
        while (dq.size() > 1) {
            dq.pop_back();
        }
        return dq.back();
    }
};
