class Solution {
    set<pair<string, int>> m;
    unordered_set<string> ans;
public:
    bool check(string &s){
        stack<char> st;
        for(auto &i:s){
            if(i=='(') st.push(i);
            else if(i==')'){
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    
    void f(int idx,string &res,string &s){
        
        if (m.find({res, idx}) != m.end()) return;
	    else m.insert({res, idx});
        
        int n=s.length();
        if(idx==n){
            if(!check(res)) return;
            if((ans.begin())->size()==res.size()) ans.insert(res);
            else if((ans.begin())->size()<res.size()) ans.clear(),ans.insert(res);
            return;
        }
        res.push_back(s[idx]);
        f(idx+1,res,s);
        res.pop_back();
        if(s[idx]!='(' and s[idx]!=')') return;
        f(idx+1,res,s);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        ans.clear(); ans.insert(""); m.clear();
        string res="";
        f(0,res,s);
        vector<string> v;
        for(auto &i:ans) v.push_back(i);
        return v;
    }
};