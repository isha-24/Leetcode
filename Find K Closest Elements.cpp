//https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> p; vector<int> res;
        for(int i : arr)
            p.push_back(make_pair(abs(i-x),i));
        sort(p.begin(),p.end());
        for(int i=0;i<k;i++)
            res.push_back(p[i].second);
        sort(res.begin(),res.end());
        return res;
    }
};
