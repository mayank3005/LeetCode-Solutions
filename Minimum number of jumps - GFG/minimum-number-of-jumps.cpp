//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int maxRange=0,cnt=0,curr=0,prev;
        if(arr[0]==0){
            if(n>1) return -1;
            return 0;
        }
        while(maxRange<n-1){
            prev=maxRange;cnt++;
            while(curr<=prev){
                maxRange=max(maxRange,arr[curr]+curr);
                curr++;
            }
            if(prev==maxRange) return -1;
        }
        if(maxRange>=n-1) return cnt;
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends