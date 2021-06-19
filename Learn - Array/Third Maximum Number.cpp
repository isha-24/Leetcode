class Solution {
public:
    int thirdMax(vector<int>& a) {
        int n=a.size();
        bool b=true;
        int max1=a[0],max2=INT_MIN,max3=INT_MIN;
        for(int i=0;i<n;i++){
            if(max1<a[i]){
                max1=a[i];
            }
        }
        for(int i=0;i<n;i++){
            if(max2<a[i] && max1!=a[i]){
                max2=a[i];
            }
        }
        if(max2==INT_MIN){
            return max1;
        }
        for(int i=0;i<n;i++){
            if(max3<a[i] && max1!=a[i] && max2!=a[i]){
                max3=a[i];
            }
            if(INT_MIN==a[i]){
                b=false;
            }
        }
        if(max3==INT_MIN && b){
            return max1;
        }
        return max3;
    }
};
