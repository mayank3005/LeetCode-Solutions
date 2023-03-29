//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   const int mod=1e9+7;
   int dp[1001];
    long long f(int h){
        if(h<0) return 0LL;
        if(h==0) return 1LL;
        if(dp[h]!=-1) return dp[h];
        return dp[h]=(2*f(h-1)%mod*f(h-2)%mod+f(h-1)*f(h-1)%mod)%mod;
    }
    long long int countBT(int h) { 
        // code here
        memset(dp,-1,sizeof(dp));
        return f(h);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends