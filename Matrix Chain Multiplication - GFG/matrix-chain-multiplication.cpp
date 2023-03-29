//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int f(int i,int j,int arr[]){
        if(i>=j) return 0;
        int &res=dp[i][j];
        if(res!=-1) return res;
        int ans=1e9;
        for(int k=i;k<j;k++){
            ans=min(ans,arr[i-1]*arr[k]*arr[j]+f(i,k,arr)+f(k+1,j,arr));
        }
        return res=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return f(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends