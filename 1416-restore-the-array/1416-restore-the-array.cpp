class Solution {
public:
    int dp[(int)1e5+5]; const int mod=1e9+7;
    int f(int idx,string &s,int k){
        int n=s.length();
        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        int &ans=dp[idx];
        if(ans!=-1) return ans;
        string temp=""; ans=0;
        for(int i=idx;i<n;i++){
            temp.push_back(s[i]);
            long val=stol(temp);
            if(val>(long)k) break;
            if(val>0) ans=(ans+f(i+1,s,k))%mod;
        }
        return ans;
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,s,k);
    }
};