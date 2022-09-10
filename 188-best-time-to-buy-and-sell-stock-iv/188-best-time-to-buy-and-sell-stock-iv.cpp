class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][2][k+1];
        for(int i=n;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=0;cap<=k;cap++){
                    if(!cap or i==n) dp[i][buy][cap]=0;
                    else{
                        if(buy) dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                        else dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};