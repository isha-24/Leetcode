//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>v; int c=-1;
        for(char ch : s){
            if(!v.empty() && ch==v[c].first)
                ++v[c].second;
            else
                v.push_back(make_pair(ch,1)), c++;
            if(v[c].second==k)
                v.pop_back(), c--;
        }
        string res;
        for(auto p : v)
            res.append(p.second, p.first);
        return res;
    }
};
