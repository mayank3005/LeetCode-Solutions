class Solution {
public:
    int dp[102][102][202];
    bool f(int a,int b,int c,string &s1,string &s2,string &s3){
        if(c<0) return 1;
        int &ans=dp[a+1][b+1][c+1];
        if(ans!=-1) return ans;
        if(a>=0 and b>=0 and s1[a]==s2[b] and s2[b]==s3[c]) return ans = f(a-1,b,c-1,s1,s2,s3) or f(a,b-1,c-1,s1,s2,s3);
        if(a>=0 and s1[a]==s3[c]) return ans = f(a-1,b,c-1,s1,s2,s3);
        if(b>=0 and s2[b]==s3[c]) return ans = f(a,b-1,c-1,s1,s2,s3);
        return ans = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.length()+s2.length()!=s3.length()) return false;
        return f(s1.length()-1,s2.length()-1,s3.length()-1,s1,s2,s3);
    }
};