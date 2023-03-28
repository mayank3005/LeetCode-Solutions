class Solution {
public:
    int f(int i,int last,vector<int> &days,vector<int> &costs,vector<vector<int>> &dp){
        if(i==days.size() or last>365) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        if(days[i]<=last) return dp[i][last]=f(i+1,last,days,costs,dp);
        else{
            int one=costs[0]+f(i+1,days[i]+1-1,days,costs,dp);
            int two=costs[1]+f(i+1,days[i]+7-1,days,costs,dp);
            int three=costs[2]+f(i+1,days[i]+30-1,days,costs,dp);
            return dp[i][last]=min({one,two,three});
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>> dp(n,vector<int>(366,-1));
        return f(0,0,days,costs,dp);
    }
};