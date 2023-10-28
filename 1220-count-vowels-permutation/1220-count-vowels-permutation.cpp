class Solution {
public:
    long dp[20002][26];
    string vowel="aeiou";
    int mod=1e9+7;
    
    long f(char prev,int i,int n){
        if(i==n) return 1;
        
        long &ans=dp[i][prev-'a'];
        if(ans!=-1) return ans;

        ans=0;
        
        if(prev=='x')
            for(auto ch:vowel) ans+=f(ch,i+1,n);
        else if(prev=='a') ans+=f('e',i+1,n);
        else if(prev=='e') {
            ans+=f('a',i+1,n);
            ans+=f('i',i+1,n);
        }
        else if(prev=='i')
            for(auto ch:vowel){
                if(ch!='i') ans+=f(ch,i+1,n);
            }
        else if(prev=='o') {
            ans+=f('i',i+1,n);
            ans+=f('u',i+1,n);
        }
        else ans+=f('a',i+1,n);
        return ans%mod;
    }
    
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return f('x',0,n);
    }
};