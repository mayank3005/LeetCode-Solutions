class Solution {
public:
    double myPow(double x, long n) {
        double ans=1; 
        if(n<0) x=1/x,n=-1*n;
        while(n){
            if(n&1) ans*=x;
            n/=2; x*=x;
        }
        return ans;
    }
};