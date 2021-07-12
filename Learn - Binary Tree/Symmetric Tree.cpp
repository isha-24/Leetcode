//https://leetcode.com/problems/symmetric-tree/

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
    int b=1;
    void calc(queue<TreeNode*> q1, queue<TreeNode*> q2){
        while(!q1.empty()){
            TreeNode* r1=q1.front(); q1.pop();
            TreeNode* r2=q2.front(); q2.pop();
            if((!r1 || !r2 )&& r1!=r2){
                b=0; return;
            }
            if(r1 && r2 && (r1->val != r2->val)){
                b=0; return;
            }
            if(r1)
                q1.push(r1->left), q1.push(r1->right);
            if(r2)
                q2.push(r2->right), q2.push(r2->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        calc(q1, q2);
        return b;
    }
};
