class Solution {
public:
    
    int dp[100002][28];
    
    int f(string &s,char prev,int n,int k){
        if(n==0){
            if(prev=='{') return 1;
            
            if(abs(prev-s[0])<=k) return 1;
            return 0;
        }
        
        int &ans=dp[n][prev-'a'];
        if(ans!=-1) return ans;
        
        if(prev=='{' or abs(prev-s[n])<=k) return ans=max(1+f(s,s[n],n-1,k),f(s,prev,n-1,k));
        
        else return ans=f(s,prev,n-1,k);
        
    }
    
    int longestIdealString(string s, int k) {
        
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(s,'{',n-1,k);
        
    }
};