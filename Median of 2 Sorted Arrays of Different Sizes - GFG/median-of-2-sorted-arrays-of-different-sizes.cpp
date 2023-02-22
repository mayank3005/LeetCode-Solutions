//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        vector<int> ans;
        int i=0,j=0,m=array1.size(),n=array2.size();
        if(m+n==0) return 0;
        while(i<m and j<n){
            if(array1[i]<array2[j]) ans.push_back(array1[i++]);
            else ans.push_back(array2[j++]);
        }
        while(i<m) ans.push_back(array1[i++]);
        while(j<n) ans.push_back(array2[j++]);
        
        int l=ans.size();
        return 1.0*(ans[l/2]+ans[(l-1)/2])/2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends