class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n); dp[0]=1;
        
        int i=0,j=0,k=0;
        
        for(int cnt=1;cnt<n;cnt++){
            
            dp[cnt]=min({dp[i]*2,dp[j]*3,dp[k]*5});
            
            if(dp[cnt]==dp[i]*2) i++;
            if(dp[cnt]==dp[j]*3) j++;
            if(dp[cnt]==dp[k]*5) k++;
        }
        return dp[n-1];
    }
};