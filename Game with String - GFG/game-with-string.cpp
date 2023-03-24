//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int freq[26]={0};
        for(auto i:s) freq[i-'a']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++) pq.push(freq[i]);
        while(!pq.empty() and k-->0){
            int val=pq.top();pq.pop();pq.push(val-1);
        }
        int ans=0;
        while(!pq.empty()){
            int val=pq.top();pq.pop();ans+=(val*val);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends