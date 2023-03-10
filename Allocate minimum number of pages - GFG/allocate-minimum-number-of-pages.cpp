//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    bool check(int arr[],int n,int m,int x){
        int curr=0;int ans=1;
        for(int i=0;i<n;i++){
            if(arr[i]>x) return false;
            curr+=arr[i];
            if(curr > x){
                curr=arr[i];ans++;
            }
        }
        return ans<=m;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M) return -1;
        //code here
        int l=0,r=accumulate(A,A+N,0);
        while(l+1<r){
            int mid=(l+r)>>1;
            if(check(A,N,M,mid)) r=mid;
            else l=mid;
        }
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends