//https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
public:
    TreeNode* r;
    vector<int> v;
    
    void helper(TreeNode* root){
        if(!root) return;
        if(root->left) {v.push_back(2*root->val+1); root->left->val=2*root->val+1;};
        if(root->right) {v.push_back(2*root->val+2); root->right->val=2*root->val+2;};
        helper(root->left);
        helper(root->right);
    }
    
    FindElements(TreeNode* root) {
        r=root;
        v.push_back(0);
        r->val=0;
        helper(r);
        sort(v.begin(), v.end());
    }
    
    bool find(int target) {
        return binary_search(v.begin(), v.end(), target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
