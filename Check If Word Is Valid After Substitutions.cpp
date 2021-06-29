//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        string res, def="abc";
        int c=0,x=0;
        for(int i=0;i<n;i++,c++){
            if(s[i]=='a')
                res.insert(c,def),x++;
            if(n/3==x)
                break;
            if(c+1>x*3)
                return false;
        }
        if(res==s) 
            return true;
        else 
            return false;
    }
};
