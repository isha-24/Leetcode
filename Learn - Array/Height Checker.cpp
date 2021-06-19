class Solution {
public:
    int heightChecker(vector<int>& arr) {
        int n=arr.size();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i]=arr[i];
        }
        int count=0;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=a[i]){
                count++;
            }
        }
        return count;
    }
};
