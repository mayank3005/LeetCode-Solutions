int mn,mx; int mod=1e9+7; string num;
int dp[23][401][2];
class Solution {
public:
    int check(string &num1){
            
            int ans = 0;
            for(int i = 0;i<num1.size();i++){
                    ans = ans + (num1[i] - '0');
            }
            
            if(ans >= mn && ans <= mx) return 1;
            return 0;
    } 
    int f(int i,int sum,bool tight){
        if(sum>mx) return 0;
        if(i==num.length()){
            return sum>=mn;
        }
        int &ans=dp[i][sum][tight];
        if(ans!=-1) return ans;
        int ub=tight?num[i]-'0':9; int res=0;
        for(int d=0;d<=ub;d++){
            res=(res+f(i+1,sum+d,tight&(d==ub)))%mod;
        }
        return ans=res;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        num=num1; mn=min_sum,mx=max_sum;
        memset(dp,-1,sizeof(dp));
        int a=f(0,0,1); 
        num=num2;
        memset(dp,-1,sizeof(dp));
        int b=f(0,0,1);
        return (b-a+check(num1)+mod)%mod;
    }
};