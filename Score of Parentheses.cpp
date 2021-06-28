//https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        int c=0; int res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(s[i+1]==')') res+=pow(2,c);
                c++;
            }
            if(s[i]==')'){
                c--;
            }
        }
        return res;
    }
};
