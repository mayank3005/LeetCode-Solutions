class Solution {
public:
    int maxx(int l,int r,vector<int> &arr){
        int mx=-1;
        for(int i=l;i<=r;i++) mx=max(mx,arr[i]);
        return mx;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]=0;
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j=i+l; dp[i][j]=1e9;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+maxx(i,k,arr)*maxx(k+1,j,arr));
                }
            }
        }
        return dp[0][n-1];
    }
};