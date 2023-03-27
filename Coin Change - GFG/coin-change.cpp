//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {

        // code here.
        long long dp[n][sum+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(!i and !j) {dp[i][j]=1;continue;}
                dp[i][j]=0;
                if(j>=coins[i]) dp[i][j]+=dp[i][j-coins[i]];
                if(i) dp[i][j]+=dp[i-1][j];
            }
        }
        
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends