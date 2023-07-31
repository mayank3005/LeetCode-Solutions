class Solution {
public:
    int dp[1001][1001];
    int f(int m,int n,string &a,string &b){
        if(m<0 or n<0){
            int ans=0;
            while(m>=0) ans+=a[m--]-'\0';
            while(n>=0) ans+=b[n--]-'\0';
            return ans;
        }
        int &ans=dp[m][n];
        if(ans!=-1) return ans;
        if(a[m]==b[n]) return ans = f(m-1,n-1,a,b);
        return ans = min( (a[m]-'\0') + f(m-1,n,a,b) , (b[n]-'\0') + f(m,n-1,a,b) );
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return f(s1.length()-1,s2.length()-1,s1,s2);
    }
};