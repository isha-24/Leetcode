class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a=0,b=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                a=i;
                b=i-1;
                break;
            }
        }
        if(nums[nums.size()-1]<0){
            a=nums.size();
            b=nums.size()-1;
        }
        for(int i=a;i<nums.size();i++){
            if(b>=0 && abs(nums[b])<nums[i]){
                ans.push_back(nums[b]*nums[b]);
                b--;
                i--;
            }
            else{
                ans.push_back(nums[i]*nums[i]);
            }
        }
        while(b>=0){
            ans.push_back(nums[b]*nums[b]);
            b--;
        }
        return ans;
    }
};
