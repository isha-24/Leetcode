//https://leetcode.com/problems/array-nesting/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                int j=i; int c=0;
                while(nums[j]>=0){
                    int temp=nums[j];
                    nums[j]=-1;
                    c++;
                    j=temp;
                }
                ans=max(ans, c);
            }
        }
        return ans;
    }
};
