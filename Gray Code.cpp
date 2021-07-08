//https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        if(n==0){
            return v;
        }
        v.push_back(1);
        int c=2;
        for(int i=2;i<=n;i++){
            for(int j=v.size()-1;j>=0;j--)
                v.push_back(c+v[j]);
            c*=2;
        }
            return v;
    }
};
