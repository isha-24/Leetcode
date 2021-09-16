//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}}); int l=0; int h=0;
        unordered_map<int, unordered_map<int, vector<int>>> mp;
        int height=1;
        while(!q.empty()){
            height+=1;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto t=q.front();
                auto r=t.first; auto p=t.second;
                if(mp.find(p.second)!=mp.end()){
                    auto &m=mp[p.second];
                    if(m.find(p.first)!=m.end()){
                        auto &v=m[p.first];
                        v.push_back(r->val);
                    }
                    else{
                        vector<int> v;
                        v.push_back(r->val);
                        m[p.first]=v;
                    }
                }
                else{
                    unordered_map<int, vector<int>> m;
                    vector<int> v; v.push_back(r->val);
                    m[p.first]=v; mp[p.second]=m;
                }
                if(r->left){
                    q.push({r->left, {p.first+1, p.second-1}});
                    l=min(l, p.second-1);
                }
                if(r->right){
                    q.push({r->right, {p.first+1, p.second+1}});
                    h=max(h, p.second+1);
                }
                q.pop();
            }
        }\
        for(int i=l;i<=h;i++){
            auto a=mp[i]; int c=0;
            vector<int> fn;
            for(int j=0;j<height;j++){
                if(a.find(c)!=a.end()){
                    auto v=a[c];
                    sort(v.begin(),v.end());
                    for(int t:v) fn.push_back(t);
                }
                c++;
            }
            res.push_back(fn);
        }
        return res;
    }
};
