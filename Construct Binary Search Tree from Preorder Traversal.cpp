//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root=new TreeNode(preorder[0]);
        st.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* t=new TreeNode(preorder[i]);
            if(!st.empty() && st.top()->val>t->val){
                st.top()->left=t;
            }
            else if(!st.empty() && st.top()->val<t->val){
                TreeNode* r;
                while(!st.empty() && st.top()->val<t->val){
                    r=st.top(); st.pop();
                }
                r->right=t;
            }
            st.push(t);
        }
        return root;
    }
};
