//https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1;
        vector<string> ans; int c=0;
        map<int, vector<string>> m2;
        for(string str : list1) m1[str]=c, c++;
        c=0;
        for(string str : list2) {
            if(m1.find(str)!=m1.end()) {
                if(m2.find(m1[str]+c)==m2.end()) {
                    vector<string> v;
                    v.push_back(str);
                    m2[m1[str]+c]=v;
                }
                else {
                    vector<string> &v=m2[m1[str]+c];
                    v.push_back(str);
                }
            }
            c++;
        }
        return m2.begin()->second;
    }
};
