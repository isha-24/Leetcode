//https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> stack;
        vector<int>ans(t.size());
        for(int i=t.size()-1;i>=0;i--){
            if(stack.empty()){
                ans[i]=0;
                stack.push({t[i],i});
            }
            else{
                while(!stack.empty() && stack.top().first<=t[i]){
                    stack.pop();
                }
                if(stack.empty()){
                    ans[i]=0;
                    stack.push({t[i],i});
                }
                else{
                    ans[i]=stack.top().second-i;
                    stack.push({t[i],i});
                }
            }
        }
        return ans;
    }
};
