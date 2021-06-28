//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    vector<int> k; int d;
    stack<int> st;
    StockSpanner() {
        d=1;
    }
    
    int next(int price) {
    k.push_back(price);
    int ans;
    while(!st.empty() && price>=k[st.top()-1])
    {
        st.pop();
    }
    if(st.empty())
        ans=d;
    else
    {
        ans=d-st.top();
    }
    st.push(d);
    d++;
    return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
