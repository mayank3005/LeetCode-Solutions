class Solution {
public:
    int dp[16];
    bool check(int n){
        while(n%5==0) n/=5;
        return n==1;
    }
    int f(int idx,string &s){
        int n=s.length();
        if(idx==n) return 0;
        if(s[idx]=='0') return 1e9;
        if(dp[idx]!=-1) return dp[idx];
        int val=0; int curr=1e9;
        for(int i=idx;i<n;i++){
            val*=2; val+=(s[i]=='1');
            if(check(val)) curr=min(curr,1+f(i+1,s));
        }
        return dp[idx]=curr;
    }
    int minimumBeautifulSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int ele=f(0,s);
        return ele>=1e9?-1:ele;
    }
};