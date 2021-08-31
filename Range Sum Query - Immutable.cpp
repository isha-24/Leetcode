//https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int>n;
    NumArray(vector<int>& nums) {
        int k=0;
        for(int i=0; i<nums.size();i++){
            k+=nums[i];
            n.push_back(k);
        }
    }
    
    int sumRange(int left, int right) {
        int l, r;
        if(left==0) l=0;
        else l=n[left-1];
        r=n[right];
        return (r-l);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
