#include<bits/stdc++.h>
class BrowserHistory {
public:
    int curr;
    vector<string> v;
    BrowserHistory(string homepage) {
        curr=0; v.push_back(homepage);
    }
    
    void visit(string url) {
        v.resize(curr+1);v.push_back(url);curr++;
    }
    
    string back(int steps) {
        curr=max(0,curr-steps);
        return v[curr];
    }
    
    string forward(int steps) {
        curr=min((int)v.size()-1,curr+steps);
        return v[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */