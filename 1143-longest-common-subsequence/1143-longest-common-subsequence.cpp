class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m=s.length(),n=t.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!i or !j) dp[i][j]=0;
                else{
                    dp[i][j]=0;
                    if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};