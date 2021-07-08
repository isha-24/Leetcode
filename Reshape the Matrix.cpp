//https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res;
        vector<int> temp; int count=0;
        int sz1=mat[0].size();
        int sz2=mat.size();
        
        if(c*r!=sz1*sz2)
            return mat;
        
        for(auto v : mat){
            for(auto a : v){
                temp.push_back(a);
                count++;
                if(count==c){
                    res.push_back(temp);
                    count=0; temp.clear();
                }
            }
        }
        return res;
    }
};
