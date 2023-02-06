class Solution {
    int dp[1000][1000];
public:
    int f(int i,int j,string &s,string &t){
        if(j<0) return 1;
        if(i<0) return 0;
        int &ans=dp[i][j];
        if(ans!=-1) return ans;
        if(s[i]==t[j]) return ans=f(i-1,j,s,t)+f(i-1,j-1,s,t);
        return ans=f(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return f(s.size()-1,t.size()-1,s,t);
    }
};