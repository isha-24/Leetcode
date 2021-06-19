class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        bool b=true;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count++;
                n--;
                if(n==i){
                    count--;
                    b=false;
                }
            }
        }
        n=arr.size();
        int x=n-1;
        for(int i=n-count-1;i>=0;i--){
            arr[x]=arr[i];
            if(arr[i]==0){
                if(b)
                    arr[--x]=arr[i];
                else
                    b=true;
            }
            --x;
        }
    }
};
