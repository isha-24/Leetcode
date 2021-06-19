class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int m=0,count=0;
    auto i=nums.begin();
    for(i=nums.begin(); i!=nums.end(); i++){
        if(*i==0){
            m=max(m,count);
            count=0;
        }
        else{
            ++count;
        }
    }
    m=max(m,count);
    return m;
    }
};
