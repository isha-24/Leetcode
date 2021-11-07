//https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true){
            if(n==1) break;
            if(s.find(n)==s.end())
                s.insert(n);
            else return false;
            int x=n, sum=0, m=0;
            while(x>0){
                m=x%10;
                sum+=(m*m);
                x=x/10;
            }
            n=sum;
        }
        return true;
    }
};
