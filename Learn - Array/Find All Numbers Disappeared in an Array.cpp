class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        vector<int> ans ;
        int n=a.size() ;
        for(int i=0;i<n;i++){
            if(a[abs(a[i])-1]>0)
                a[abs(a[i])-1]*=-1 ;
        }
        for(int i=0;i<n;i++)
            if(a[i]>0) ans.push_back(i+1) ;
        return ans ;
        
    }
};
