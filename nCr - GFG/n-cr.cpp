//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    long long int M=1e9+7;
public:
    int dp[1001][801];
    int solve(int n,int r){
        if(n<r) return 0; 
        if(!r || n==r) return 1;
        
        if(dp[n][r]!=-1) return dp[n][r];
            
        int left,right;    
        left=solve(n-1,r);
        right=solve(n-1,r-1);
            
        return dp[n][r]=((long long)left+right)%M;
        
    }
    int nCr(int n, int r){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n,r);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends