//https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int count=0, a;
        vector<int> v;
        for(int i=0;i<n;i++){
            a=arr[i]; count=0;
            while(i<n && a==arr[i]){
                i++, count++;
            }
            i--;
            v.push_back(count);
        }
        sort(v.begin(), v.end(), greater<int>());
        count=0; int ans=0;
        for(int i : v){
            count+=i;
            ans++;
            if(count>=n/2){
                break;
            }
        }
        return ans;
    }
};
