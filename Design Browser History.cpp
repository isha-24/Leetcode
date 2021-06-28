//https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
public:
    vector<string>s;
    int tot=0;
    int visited=0;
    BrowserHistory(string homepage) {
        s.push_back("NULL");
        s.push_back(homepage);
        tot++;
        visited=1;
    }
    
    void visit(string url) {
        if(visited==tot){
            s.push_back(url);
            visited++;
            tot++;
        }
        else{
            while(visited!=tot){
                s.pop_back();
                tot--;
            }
            s.push_back(url);
            visited++;
            tot++;
        }
    }
    
    string back(int steps) {
        if(visited-steps>0){
            int x=visited-steps;
            visited=visited-steps;
            return s[x];
        }
        else{
            visited=1;
            return s[1];
        }
    }
    
    string forward(int steps) {
        if(steps+visited<=tot){
            int x=visited+steps;
            visited=visited+steps;
            return s[x];
        }
        else{
            visited=tot;
            return s[tot];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
