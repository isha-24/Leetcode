//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> bts;
        int sum = 0;
        TreeNode* cur = root;
        
        while (cur || !bts.empty()) {
            while (cur) {
                bts.push(cur);
                cur = cur->right;
            }
            cur = bts.top();
            bts.pop();
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
        }
        return root;
    }
};
