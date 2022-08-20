class Solution {
public:
    bool solve(string &s,string &t,int m,int n,vector<vector<int>> &dp){
        if(n<0 and m<0) return true;
        if(n<0 and m>=0) return false;
        if(n>=0 and m<0){
            if(t[n]=='*') return solve(s,t,m,n-1,dp);
            else return false;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(s[m]==t[n] or t[n]=='?') return dp[m][n]=solve(s,t,m-1,n-1,dp);
        else if(t[n]=='*') return dp[m][n]=solve(s,t,m-1,n-1,dp) or solve(s,t,m-1,n,dp) or solve(s,t,m,n-1,dp);
        return dp[m][n]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(s,p,m-1,n-1,dp);
    }
};