class Solution {
public:
    // dp[i][j] --> min steps to create n chars given i characters and j chars on clipboard
    int minSteps(int n) {
        int dp[n+1][n+1]; 
        for(int i=0;i<=n;i++) dp[n][i]=0;
        for(int i=n-1;i>0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=1e8;
                if(i+j<=n) dp[i][j]=1+dp[i][i];
                if(i+j<=n) dp[i][j]=min(dp[i][j],1+dp[i+j][j]);
            }
        }
        return dp[1][0];
    }
};