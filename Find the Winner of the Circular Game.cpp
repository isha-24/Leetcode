//https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
 int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=1;i<=n; i++)v[i-1]=i;
        int c=0;
        while(v.size()>1){
            c = (c+k-1)%v.size();
            v.erase(v.begin()+c);
        }
        return v[0];
    }
};
