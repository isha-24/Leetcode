//https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!s.empty() && s.top()>0 && a[i]<0) {
                int x=a[i]*(-1);
                while(!s.empty() && x>s.top() && s.top()>0){
                    s.pop();
                }
                if(!s.empty() && x==s.top() && s.top()>0) {s.pop(); continue;}
                if(s.empty() || x>s.top()) s.push(a[i]);
            }
            else s.push(a[i]);
        }
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
