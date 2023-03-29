class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        int dp[n+1][n+2];
        for(int i=n;i>=0;i--){
            for(int j=1;j<=n+1;j++){
                if(i==n) dp[i][j]=0;
                else{
                    dp[i][j]=dp[i+1][j];
                    if(j<=n) dp[i][j]=max(dp[i][j],j*sat[i]+dp[i+1][j+1]);
                }
            }
        }
        return dp[0][1];
    }
};