//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        string m;
        for(int i=0;i<s.length();i++)
        {
            if(m.size()!=0 && m[m.size()-1]==s[i])
            {
                m.pop_back();
            }
            else
            {
                m.push_back(s[i]);
            }
        }
        return m;
    }
};
