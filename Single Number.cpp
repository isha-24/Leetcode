//https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums){
            if(s.find(i)==s.end())
                s.insert(i);
            else s.erase(i);
        }
        auto itr=s.begin();
        return *itr;
    }
};
