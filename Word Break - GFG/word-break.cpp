//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    unordered_map<string,bool> mp;
    int dp[1101];
public:

    int f(int idx,string &s){
        int n=s.length();
        if(idx==n) return 1;
        
        int &ans=dp[idx];
        if(ans!=-1) return ans;
        
        string curr="";int curr_ans=0;
        for(int i=idx;i<n;i++){
            curr.push_back(s[i]);
            if(mp.find(curr)!=mp.end()) curr_ans+=f(i+1,s);
        }
        return ans=curr_ans;
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        mp.clear(); memset(dp,-1,sizeof(dp));
        for(auto &i:B) mp[i]=true;
        f(0,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends