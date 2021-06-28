//https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m; vector<int> ans;
        for(int i : nums1) m[i]++;
        for(int i : nums2){
            if(m.find(i)!=m.end() && m[i]>0){
                m[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
