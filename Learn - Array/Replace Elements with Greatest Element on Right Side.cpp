class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int mx=arr[n-1];
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                ans[i]=-1;
                continue;
            }
            ans[i]=mx;
            mx=max(mx,arr[i]);
        }
        return ans;
    }
};
