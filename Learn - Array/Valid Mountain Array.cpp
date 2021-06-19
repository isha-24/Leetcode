class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        bool b=true;
        bool b2=false;
        for(int i=1;i<n;i++){
            if(i+1<n && arr[i]>arr[i+1] && arr[i]>arr[i-1] && !b2){
                b=false;
                b2=true;
                continue;
            }
            if(b){
                if(arr[i]<=arr[i-1]){
                    return false;
                }
            }
            else{
                if(arr[i]>=arr[i-1]){
                    return false;
                }
            }
        }
        if(b2){
            return true;
        }
        else{
            return false;
        }
    }
};
