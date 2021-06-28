//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        vector<int> index;
        int c=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                index.push_back(i);
                c++;
            }
            if(s[i]==')'){
                if(c==0){
                    s[i]='-';
                }
                else{
                    index.pop_back();
                    c--;
                }
            }
        }
        
        for(int i:index){
            s[i]='-';
        }
        
        string res;
        for(char ch:s){
            if(ch!='-'){
                res+=ch;
            }
        }
        return res;
    }
};
