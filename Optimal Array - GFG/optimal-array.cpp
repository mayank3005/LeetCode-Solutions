//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int> ans; vector<int> pref(n+1);pref[0]=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            pref[i]=a[i-1];pref[i]+=pref[i-1];
        }
        for(int i=0;i<n;i++){
            int median =(a[i/2]+a[(i+1)/2])/2; 
            int curr=((i+1)/2+(i+1)%2)*median - pref[i/2+1];
            curr+=(pref[i+1]-pref[i/2+1] - median*(i+1-((i+1)/2+(i+1)%2)));
            ans.push_back(curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends