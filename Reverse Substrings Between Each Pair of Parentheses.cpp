//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int> stack;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stack.push(i);
            }
            else if(s[i]==')'){
                reverse(s.begin()+stack.top()+1,s.begin()+i);
                stack.pop();
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
        }
        return ans;
    }
};
