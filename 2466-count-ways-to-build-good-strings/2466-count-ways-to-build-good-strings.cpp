class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[high+1]; dp[0]=1; int mod=1e9+7;
        for(int i=1;i<=high;i++){
            dp[i]=0;
            if(i>=zero) dp[i]=(dp[i]+dp[i-zero])%mod;
            if(i>=one) dp[i]=(dp[i]+dp[i-one])%mod;
        }
        int ans=0;
        for(int i=low;i<=high;i++) ans=(ans+dp[i])%mod;
        return ans;
    }
};