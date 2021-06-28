//https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        unordered_set<int> s;
        unordered_set<int> e;
        int n=a.size();
        int p=0;
        if(k==0){
            for(int i=0;i<n;i++){
                if(e.find(a[i])==e.end() && s.find(a[i])!=s.end()){
                    p++;
                    s.erase(a[i]);
                    e.insert(a[i]);
                }
                else{
                    s.insert(a[i]);
                }
            }
            return p;
        }
        for(int i=0;i<n;i++){
            if(s.find(a[i])==s.end() && s.find(a[i]+k)!=s.end()){
                p++;
            }
            if(s.find(a[i])==s.end() && s.find(a[i]-k)!=s.end()){
                p++;
            }
            s.insert(a[i]);
        }
        return p;
    }
};
