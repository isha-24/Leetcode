//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "null ";
        queue<TreeNode*> q; string s;
        q.push(root); s=to_string(root->val)+" ";
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                    s+=to_string(t->left->val)+" ";
                }
                else{
                    s+="null ";
                }
                if(t->right){
                    q.push(t->right);
                    s+=to_string(t->right->val)+" ";
                }
                else{
                    s+="null ";
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        string t; queue<TreeNode*> q; int l=0;
        int first=1; TreeNode* root=NULL;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                t+=s[i];
            }
            else{
                if(first==1){
                    if(t=="null"){
                        TreeNode* temp=NULL;
                        return temp;
                    }
                    else{
                        TreeNode* temp=new TreeNode(stoi(t));
                        root=temp;
                        q.push(temp);
                    }
                    first=0;
                }
                else if(t=="null"){
                    if(l==0) l=1;
                    else{
                        q.pop();
                        l=0;
                    }
                }
                else{
                    TreeNode* temp=new TreeNode(stoi(t));
                    if(l==0){
                        q.front()->left=temp;
                        l=1;
                    }
                    else{
                        q.front()->right=temp;
                        q.pop();
                        l=0;
                    }
                    q.push(temp);
                }
                t="";
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));;
