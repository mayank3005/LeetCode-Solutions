int mod=1e9+7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        int dp[n][t+1];
        
        for(int i=0;i<=t;i++){
            if(i>=1 and i<=k) dp[0][i]=1;
            else dp[0][i]=0;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                dp[i][j]=0;
                for(int c=1;c<=k;c++){
                    if(j<c) break;
                    dp[i][j]=(dp[i][j]+dp[i-1][j-c])%mod;
                }
            }
        }
        
        return dp[n-1][t];
    }
};