class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; int n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(!st.empty() and s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        int ans=0,a=n,b=-1;
        while(!st.empty()){
            int b=st.top();st.pop();
            ans=max(ans,a-b-1); a=b;
        }
        ans=max(ans,a-b-1);
        return ans;
    }
};