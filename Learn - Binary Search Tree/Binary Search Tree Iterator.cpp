//https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
    vector<int> v; int c=0;
    
    void bst(TreeNode* root) {
        if(!root) return;
        bst(root->left);
        v.push_back(root->val);
        bst(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        bst(root);
    }
    
    int next() {
        int k=v[c];
        c++;
        return k;
    }
    
    bool hasNext() {
        if(c<v.size()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
