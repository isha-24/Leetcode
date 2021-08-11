//https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char, char> m;
        unordered_map<char, int> num;
        for(int i=0; i<s.length(); i++){
            if(m.find(t[i])==m.end()){
                m[t[i]]=s[i]; 
                if(num[s[i]]<1) num[s[i]]++;
                else return false;
            }
            else{
                if(m[t[i]]!=s[i])
                    return false;
            }
        }
        return true;
    }
};
