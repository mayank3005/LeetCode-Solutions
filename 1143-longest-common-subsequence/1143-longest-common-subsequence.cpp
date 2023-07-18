class Solution {
public:
    int dp[1001][1001];
    int f(int m,int n,string &s,string &t){
        if(m<0 or n<0) return 0;
        int &ans=dp[m][n];
        if(ans!=-1) return ans;
        if(s[m]==t[n]) ans=1+f(m-1,n-1,s,t);
        return ans=max(ans,max(f(m-1,n,s,t),f(m,n-1,s,t)));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return f(text1.size()-1,text2.size()-1,text1,text2);
    }
};