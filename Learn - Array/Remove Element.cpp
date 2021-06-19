class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int x=n;
        int d=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(i<n && nums[i]==val){
                x--;
                i++;
                d++;
            }
            if(i<n)
            nums[i-d]=nums[i];
        }
        return x;
    }
};
