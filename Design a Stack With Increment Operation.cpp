//https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    int n,tot=0;
    vector<int> a;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(tot<n){
            a.push_back(x);
            tot++;
        }
    }
    
    int pop() {
        int e=-1;
        if(tot>0){
            e=a.back();
            tot--;
            a.pop_back();
        }
        return e;
    }
    
    void increment(int k, int val) {
        int t=0;
        while(t<tot && k--){
            a[t]+=val;
            t++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
