class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        vector<int> dp(502,0);
        
        dp[0]=startFuel;
        int n=stations.size();
        for(int i=0;i<n;i++){
            for(int t=i;t>=0 and dp[t]>=stations[i][0] ;t--){
                dp[t+1]=max(dp[t+1],(int)min(target*1LL,dp[t]*1LL+stations[i][1]));
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            if(dp[i]>=target) return i;
        }
        return -1;
    }
};