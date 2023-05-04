class Solution {
public:
    int mod=pow(10,9)+7;
    int dp[5001][4][3];
    long solve(int i,int j,int n)
    {
        if(i>=4 or i<0 or j>=3 or j<0 or (i==3 and j!=1))
            return 0;
        
        if(n==1)
            return 1;
        
        if(dp[n][i][j]!=-1)
            return dp[n][i][j];
        int res=  ( solve(i - 1, j - 2,n-1)%mod+
                    solve(i - 2, j - 1,n-1)%mod+
                    solve(i - 2, j + 1,n-1)%mod+
                    solve(i - 1, j + 2,n-1)%mod+
                    solve(i + 1, j + 2,n-1)%mod+
                    solve(i + 2, j + 1,n-1)%mod+
                    solve(i + 2, j - 1,n-1)%mod+
                    solve(i + 1, j - 2,n-1)%mod)%mod;
            
            return dp[n][i][j]=res;
    }
    int knightDialer(int n) {
        long count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==3 and j!=1)
                    continue;
                count=(count+solve(i,j,n))%mod;
            }
        }
        return count;
    }
};