//https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> n(26,0);
        for(char ch:str){
            n[ch-'a']++;
        }
        string res="";
        for(char ch:order){
            while(n[ch-'a']>0){
                res+=ch;
                n[ch-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(n[i]>0){
                res+=(char)i+'a';
                n[i]--;
            }
        }
        return res;
    }
};
