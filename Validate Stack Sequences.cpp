//https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(pushed[i]==popped[c]){
                c++;
                continue;
            }
            if(!st.empty() && st.top()==popped[c]){
                c++;i--;
                st.pop();
                continue;
            }
            st.push(pushed[i]);
        }
        while(!st.empty() && c<n && popped[c]==st.top()){
            c++;
            st.pop();
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
