class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int l=0;int r=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[l]=nums[i];
                l++;
            }
            else{
                ans[r]=nums[i];
                r--;
            }
        }
        return ans;
    }
};
