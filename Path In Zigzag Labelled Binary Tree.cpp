//https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> v;
        int n=ceil(log(label+1)/log(2));
        int diff=pow(2,n-1); int c=n-1;int pa=label;
        for(int i=n-1;i>=1;i--){
            v.push_back(pa);
            int prevs=pow(2,i)-1;
            int af;
            if(c%2==1){
                int s=prevs+diff;
                af=s-pa+1;
            }
            else{
                int s=prevs;
                af=diff-(pa-s)+1;
            }
            pa=(prevs+af)/2;
            diff/=2;c--;
        }
        v.push_back(1);
        reverse(v.begin(), v.end());
        return v;
    }
};
