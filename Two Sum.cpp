//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            if(m.find(target-a)==m.end())
                m[a]=i;
            else {
                ans.push_back(m[target-a]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
