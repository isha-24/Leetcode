//https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        string optS; int c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='#'){
                if(c==0) optS=s[i]+optS;
                else c--;
            }
            else c++;
        }
        n=t.length();
        string optT; c=0;
        for(int i=n-1;i>=0;i--){
            if(t[i]!='#'){
                if(c==0) optT=t[i]+optT;
                else c--;
            }
            else c++;
        }
        if(optS==optT) return true;
        else return false;
    }
};
