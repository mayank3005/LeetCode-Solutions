int dp[1001][1001];

class Solution {
public:
    int ans,ansl,ansr;
    int f(string &s,int i,int j){
        
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(i+1==j){
            int ret=0;
            if(s[i]==s[j]) 
                ret=2;
            if(ans<ret) ans=ret,ansl=i,ansr=j;
            return ret;
        }
        
        if(dp[i][j]!=-1) return dp[i][j]; 
        
        int val=f(s,i+1,j-1);
        if(s[i]==s[j] and val) {
            
            if(ans<val+2) ans=val+2,ansl=i,ansr=j;
            return dp[i][j]=val+2;
            
        }
        else{
            f(s,i+1,j),f(s,i,j-1);
            return dp[i][j]=0;
        }
        
    }
    
    string longestPalindrome(string s) {
        
        ans=0,ansl=-1;
        memset(dp,-1,sizeof(dp));
        f(s,0,s.size()-1);
        
        if(ansl==-1) return s.substr(0,1);
        return s.substr(ansl,ansr-ansl+1);
        
    }
};