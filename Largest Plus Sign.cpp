//https://leetcode.com/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> x;
            for(int j=0;j<n;j++)
                x.push_back(1);
            a.push_back(x);
        }
        for(auto x : mines) a[x[0]][x[1]]=0;
        int px[n][n], nx[n][n], py[n][n], ny[n][n];
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(a[i][j]==0) sum=0;
                sum+=a[i][j];
                px[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=n-1;j>=0;j--){
                if(a[i][j]==0) sum=0;
                sum+=a[i][j];
                nx[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(a[j][i]==0) sum=0;
                sum+=a[j][i];
                py[j][i]=sum;
            }
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=n-1;j>=0;j--){
                if(a[j][i]==0) sum=0;
                sum+=a[j][i];
                ny[j][i]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int m1=min(nx[i][j],ny[i][j]);
                int m2=min(py[i][j],px[i][j]);
                ans=max(ans, min(m1,m2));
            }
        }
        return ans;
    }
};
