class Solution {
public:
    int dp[50][50];
    int minScoreTriangulation(vector<int>& v) {
        int n=v.size();
        for(int g=1;g<n;g++){
            for(int i=n-g-1;i>=0;i--){
                int j=i+g;
                for(int k=i+1;k<j;k++){
                    int val=(dp[i][j]==0?1e9:dp[i][j]);
                    dp[i][j]=min(val,dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
                    // cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j]<<endl;
                }
            }
        }
        return dp[0][n-1];
    }
};