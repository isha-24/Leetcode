//https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.length();
        vector<int> a(n,0);
        int prev=0;
        int b=0;int mx=0,mxi=-1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                b++;
                a[i]=b;
                mx=max(b,mx);
            }
            else{
                a[i]=b;
                b--;
            }
        }
        int lvl=mx/2;
        for(int &i:a){
            if(i>lvl)
                i=1;
            else
                i=0;
        }
        return a;
    }
};
