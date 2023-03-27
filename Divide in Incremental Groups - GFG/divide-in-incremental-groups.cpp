//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[101][101][102];
    int f(int sum,int k,int last){
        if(k==0) return !sum;
        int &ans=dp[sum][k][last];
        if(ans!=-1) return ans;
        ans=0;
        for(int i=sum;i>=1;i--){
            if(i<=last) ans+=f(sum-i,k-1,i);
        }
        return ans;
    }
  
    int countWaystoDivide(int N, int K) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return f(N,K,101);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends