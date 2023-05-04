class Solution {
public:
    double dp[25][25][101];
    int dirx[8]={-1,-1,-2,-2,1,1,2,2};
    int diry[8]={-2,2,-1,1,-2,2,-1,1}; 
    double f(int r,int c,int n,int k){
        if(r>=n or r<0 or c>=n or c<0) return 0;
        if(k<=0) return 1;
        double &ans=dp[r][c][k];
        if(ans>0) return ans;
        ans=0;
        for(int i=0;i<8;i++){
            int xx=dirx[i],yy=diry[i];
            ans+=f(r+xx,c+yy,n,k-1)/8.0;
        }
        // cout<<r<<" "<<c<<" "<<ans<<endl;
        return ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1,sizeof(dp));
        return f(row,column,n,k);
    }
};