//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n][W+1];
       for(int i=0;i<n;i++){
           for(int j=W;j>=0;j--){
               if(!i){
                   if(j>=wt[i]) dp[i][j]=val[0];
                   else dp[i][j]=0;
                   continue;
               }
               dp[i][j]=dp[i-1][j];
               if(j>=wt[i]) dp[i][j]=max(dp[i][j],val[i]+dp[i-1][j-wt[i]]);
           }
       }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends