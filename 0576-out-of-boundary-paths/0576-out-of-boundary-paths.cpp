class Solution {
public:
    int dp[51][51][51]; int mod=1e9+7;
    int f(int i,int j,int mm,int m,int n){
        if(i<0 or i>=m or j<0 or j>=n) return mm>=0;
        if(mm<0) return 0;
        int &ans=dp[i][j][mm];
        if(ans!=-1) return ans;
        int dx[5]={0,-1,0,1,0}; int temp=0;
        for(int k=0;k<4;k++){
            temp=(temp+f(i+dx[k],j+dx[k+1],mm-1,m,n))%mod;
        }
        return ans=temp;
    }
    int findPaths(int m, int n, int mm, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return f(sr,sc,mm,m,n);
    }
};