class Solution {
public:
    long long dp[17][2];
    long long f(string &num,int i,bool tight,string &s,int limit){
        if(s.length()>num.length()) return 0LL;
        if(i==num.length()) return 1LL;
        
        long long &ans=dp[i][tight];
        if(ans!=-1) return ans;
        
        int idx=num.length()-s.length();
        
        int ub=tight?num[i]-'0':9;
        if(i>=idx){
            if(tight and s[i-idx]>num[i]) return ans=0LL;
            else return ans=f(num,i+1,tight&(s[i-idx]==num[i]),s,limit);
        }
        
        ub=min(ub,limit);
        long long res=0LL;
        for(int d=0;d<=ub;d++){
            res+=f(num,i+1,tight&(num[i]-'0'==d),s,limit);
        }
        return ans=res;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        memset(dp,-1LL,sizeof(dp));
        string L=to_string(start-1),R=to_string(finish);
        long long a=f(L,0,1,s,limit); 
        memset(dp,-1LL,sizeof(dp));
        long long b=f(R,0,1,s,limit);
        return b-a;
    }
};