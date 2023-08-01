class Solution {
public:
    int dp[1001][1001];
    int f(int i,string &a,int nc,int len){
        int n=a.length();
        if(nc<0) return INT_MAX;
        if(i>=n) return 0;
        int &ans=dp[i][nc];
        if(ans!=-1) return ans;
        return ans = min( (a[i]-'0') +f(i+1,a,nc,len) , f(i+len,a,nc-1,len));
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp,-1,sizeof(dp));
        return f(0,floor,numCarpets,carpetLen);
    }
};