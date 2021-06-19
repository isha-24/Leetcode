class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(i+1<n && arr[i+1]==0){
                    return true;
                }
                if(i-1>=0 && arr[i-1]==0){
                    return true;
                }
                continue;
            }
            bool b=binary_search(arr.begin(),arr.end(),arr[i]*2);
            if(b){
                return b;
            }
        }
        return false;
    }
};
