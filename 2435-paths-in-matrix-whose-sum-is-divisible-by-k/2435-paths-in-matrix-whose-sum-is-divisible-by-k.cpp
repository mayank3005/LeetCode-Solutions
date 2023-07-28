class Solution {
public:
    const int mod=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int kk) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n][kk+1]; memset(dp,0,sizeof(dp));
        dp[0][0][grid[0][0]%kk]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<kk;k++){
                    int val=(kk+k-(grid[i][j]%kk))%kk;
                    if(!i or !j){
                        if(!i and !j) continue;
                        else if(!i) dp[i][j][k]=dp[i][j-1][val];
                        else if(!j) dp[i][j][k]=dp[i-1][j][val];
                        continue;
                    }
                    dp[i][j][k]=(dp[i-1][j][val]+dp[i][j-1][val])%mod;
                    
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};