class Solution {
public:
    int dp[21][21];
    bool f(int m,int n,string &s,string &p){
        if(n<0) return m<0;
        if(m<0){
            while(n>=0 and p[n]=='*') n-=2;
            return n<0;
        }
        int &ans=dp[m][n];
        if(ans!=-1) return ans;
        if(s[m]==p[n] or p[n]=='.') return ans=f(m-1,n-1,s,p);
        if(p[n]=='*'){
            if(p[n-1]==s[m] or p[n-1]=='.') return ans = f(m,n-2,s,p) or f(m-1,n,s,p);
            else return ans = f(m,n-2,s,p);
        }
        return ans=false;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return f(s.length()-1,p.length()-1,s,p);
    }
};