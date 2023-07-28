class Solution {
public:
    int dp[1002][2][101];
    int f(int i,bool buy,const vector<int> &prices,int k){
        if(i==prices.size() or k==0) return 0;
        int &ans=dp[i][buy][k];
        if(ans!=-1) return ans;
        if(buy) return ans = max( -prices[i]+f(i+1,0,prices,k) , f(i+1,1,prices,k) );
        return ans = max( prices[i]+f(i+1,1,prices,k-1) , f(i+1,0,prices,k) );
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,1,prices,k);        
    }
};