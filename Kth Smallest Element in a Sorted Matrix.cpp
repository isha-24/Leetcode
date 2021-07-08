//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> p;
        for(auto i : matrix){
            for(int j : i){
                p.push(j);
            }
        }
        for(int i=1;i<k;i++){
            p.pop();
        }
        return p.top();
    }
};
