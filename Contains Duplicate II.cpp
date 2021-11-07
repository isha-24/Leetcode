//https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int l;
        
        if(k<nums.size()-1) l=k;
        else l=nums.size()-1;
        
        for(int i=0;i<=l;i++) {
            if(s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else return true;
        }
        for(int i=l+1; i<nums.size();i++){
            s.erase(nums[i-k-1]);
            if(s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else return true;
        }
        return false;
    }
};
