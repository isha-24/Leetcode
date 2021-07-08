//https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
public:
    queue<int> q; int c;
    RecentCounter() {
        c=0;
    }
    
    int ping(int t) {
        q.push(t);
        c++;
        while(q.front() < (t-3000))
            q.pop(), c--;
        return c;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
