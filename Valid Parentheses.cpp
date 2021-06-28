//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else{
                if(ch==')'){
                    if(st.empty() || st.top()!='(')
                        return false;
                    else
                        st.pop();
                }
                if(ch=='}'){
                    if(st.empty() || st.top()!='{')
                        return false;
                    else
                        st.pop();
                }
                if(ch==']'){
                    if(st.empty() || st.top()!='[')
                        return false;
                    else
                        st.pop();
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
