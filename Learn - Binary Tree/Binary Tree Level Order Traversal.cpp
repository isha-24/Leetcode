//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> res;
        if(!root)
            return res;
        q.push(root);
        vector<int> t;
        t.push_back(root->val);
        res.push_back(t);
        while(!q.empty()){
            int n=q.size();
            t.clear();
            while(n--){
                if(q.front()->left){
                    t.push_back(q.front()->left->val);
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    t.push_back(q.front()->right->val);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(t.size())
                res.push_back(t);
        }
        return res;
    }
};
