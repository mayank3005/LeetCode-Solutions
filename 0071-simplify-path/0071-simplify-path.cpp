class Solution {
public:
    string simplifyPath(string A) {

        stack<string> st;
        if(A.back()!='/') A.push_back('/');
        stringstream ss(A);
        string s="";
        while(getline(ss,s,'/')){
            if(s.length()==0 or s==".") continue;
            if(s=="..") {if(!st.empty()) st.pop();}
            else st.push(s);
        }    
        if(st.empty()) return "/";
        vector<string> res;
        while(!st.empty()){
            res.push_back(st.top());st.pop();
        }
        int i=res.size()-1;
        string ans;
        while(i>=0){
            ans.push_back('/');
            ans.append(res[i--]);
        }
        return ans;

        
    }
};