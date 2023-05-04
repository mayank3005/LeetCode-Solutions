class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); int dp[n][amount+1];
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e8;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i]) dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
            }
        }
        return dp[n-1][amount]>=1e8?-1:dp[n-1][amount];
    }
};