class Solution {
public:
    int mod=1e9+7;
    int dp[101][101][101];
    int f(int n,int num,int minprof,vector<int> &g,vector<int> &p){
        if(n<0) return minprof<=0;
        minprof=max(0,minprof);
        int &ans=dp[n][num][minprof];
        if(ans!=-1) return ans;
        int take=0,notTake=f(n-1,num,minprof,g,p);
        if(num>=g[n]) take=f(n-1,num-g[n],minprof-p[n],g,p);
        return ans=(take+notTake)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return f(group.size()-1,n,minProfit,group,profit);
    }
};