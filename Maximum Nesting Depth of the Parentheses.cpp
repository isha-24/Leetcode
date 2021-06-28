//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int c=0,mx=0;
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
                c++;
            }
            else if(ch==')'){
                st.pop();
                c--;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};
