class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=accumulate(stones.begin(),stones.end(),0);
        int dp[n][sum+1]; 
        for(int i=0;i<=sum;i++) dp[0][i]=0;
        dp[0][0]=dp[0][stones[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=stones[i]) dp[i][j]|=dp[i-1][j-stones[i]];
            }
        }
        int ans=1e9;
        for(int i=0;i<=sum;i++){
            if(dp[n-1][i]) ans=min(ans,abs(2*i-sum));
        }
        return ans;
    }
};