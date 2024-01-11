string num; int k;
int dp[10][10][10][21][2][2];
class Solution {
public:
    int f(int i,int odd,int even,int rem,bool tight,bool isStarted){
        
        if(i==num.length()){
            return (odd==even and rem==0 and isStarted);
        }
        
        int &ans=dp[i][odd][even][rem][tight][isStarted];
        if(ans!=-1) return ans;
        
        int ub=tight?num[i]-'0':9; int res=0;
        for(int d=0;d<=ub;d++){
            
            bool isStarted1=(isStarted || d!=0);
            
            int odd1=odd,even1=even;
            if(isStarted1){
                if(d%2==0) odd1=odd+1;
                else even1=even1+1;
            }
            
            int rem1=(rem*10%k+d)%k;
            
            res+=f(i+1,odd1,even1,rem1,tight&(d==ub),isStarted1);
        }
        return ans=res;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k1) {
        memset(dp,-1,sizeof(dp));
        string L=to_string(low-1),R=to_string(high);
        num=L;k=k1; int a=0;
        if(low>=1) a=f(0,0,0,0,1,0);
        num=R; int b=0;
        memset(dp,-1,sizeof(dp));
        b=f(0,0,0,0,1,0);
        return b-a;
    }
};