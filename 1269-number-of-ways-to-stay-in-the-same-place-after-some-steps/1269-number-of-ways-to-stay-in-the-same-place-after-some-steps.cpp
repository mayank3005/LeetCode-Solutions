class Solution {
public:
    int numWays(int s, int n) {
        n=min(n,s);
        const int mod=1e9+7;
        int dp[n];
        for(int i=0;i<n;i++) dp[i]=0;
        dp[0]=1;
        for(int i=1;i<=s;i++){
            int prev=0;
            for(int j=0;j<n;j++){
                int one,two,three;one=two=three=0;
                if(j>0) one=prev;
                two=dp[j];
                if(j<n-1) three=dp[j+1];
                prev=dp[j];
                dp[j]=((one+two)%mod+three)%mod;
            }
        }
        return dp[0];
    }
};