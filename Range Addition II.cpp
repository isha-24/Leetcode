//https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mnx=m; int mny=n;
        for(auto a : ops){
            mnx=min(a[0], mnx);
            mny=min(a[1], mny);
        }
        return mnx*mny;
    }
};
