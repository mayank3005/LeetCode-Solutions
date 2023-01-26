//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool dfs(int src,vector<int> adj[],vector<int> &vis,vector<int> & pathvis,vector<int> &check){
       vis[src]=pathvis[src]=1;
       check[src]=0;
       for(auto it:adj[src]){
           if(!vis[it]) {
               if(dfs(it,adj,vis,pathvis,check)) return true;
           }
           else if(pathvis[it]){
               check[it]=0;
               return true;
           }
       }
       check[src]=1;
       pathvis[src]=0;
       return false;
   }
  
  
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n);
        vector<int> ans;
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends