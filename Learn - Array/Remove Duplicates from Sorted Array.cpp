class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            nums[j]=nums[i];
            j++;
            while(i+1<n && nums[j-1]==nums[i+1]){
                count++;
                i++;
            }
        }
        return (n-count);
    }
};
