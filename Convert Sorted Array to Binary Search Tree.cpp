//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* helper(int l, int r, vector<int>& nums){
        if(r==l) return NULL;
        if(r-l==1){
            TreeNode* t=new TreeNode(nums[l]);
            return t;
        }
        TreeNode* root=new TreeNode(nums[(r+l)/2]);
        root->left=helper(l, (r+l)/2, nums);
        root->right=helper((r+l)/2+1, r, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=helper(0, nums.size(), nums);
        return root;
    }
};
