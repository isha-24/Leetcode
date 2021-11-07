//https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        for(int i : nums1) {
            s.insert(i);
        }
        for(int i : nums2){
            if(s.find(i)!=s.end()){
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};
