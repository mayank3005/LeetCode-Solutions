class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b=""; stack<char> st;
        for(auto i:s){
            if(i=='#' and st.size()) st.pop();
            else if(i!='#') st.push(i);
        }
        while(!st.empty()) a.push_back(st.top()),st.pop();
        for(auto i:t){
            if(i=='#' and st.size()) st.pop();
            else if(i!='#') st.push(i);
        }
        while(!st.empty()) b.push_back(st.top()),st.pop();
        cout<<a<<endl;cout<<b<<endl;
        return a==b;
    }
};