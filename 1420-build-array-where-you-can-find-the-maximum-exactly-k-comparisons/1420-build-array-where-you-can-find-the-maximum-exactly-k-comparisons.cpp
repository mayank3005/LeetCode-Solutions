const int mod=1e9+7;
int dp[52][102][52];
class Solution {
public:    
    int f(int n,int m,int last_max,int k){
        if(n==0) return k==0;
        if(k<0) return 0;
        int &ans=dp[n][last_max][k];
        if(ans!=-1) return ans;
        ans=0;
        for(int i=1;i<=last_max;i++) ans=(ans+f(n-1,m,max(i,last_max),k))%mod;
        for(int i=last_max+1;i<=m;i++) ans=(ans+f(n-1,m,i,k-1))%mod;
        return ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,m,0,k);
    }
};