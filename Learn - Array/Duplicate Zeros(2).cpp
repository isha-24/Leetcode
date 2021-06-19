class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int> a;
        for(int i=0;i<n;i++){
            a.push_back(arr[i]);
            if(arr[i]==0){
                a.push_back(0);
                n-=1;
            }
        }
        n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
    }
};
