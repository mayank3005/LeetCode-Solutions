//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void topo(int src,vector<pair<int,int>> adj[],stack<int> &st,vector<int> &vis){
        vis[src]=1;
        for(auto it:adj[src]){
            int dest=it.first;
            if(!vis[dest]) topo(dest,adj,st,vis);
        }
        st.push(src);
    }
  
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int>> adj[n];
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> vis(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topo(i,adj,st,vis);
            }
        }
        
        vector<int> dist(n,1e9);
        dist[0]=0;
        while(!st.empty()){
            int src=st.top();st.pop();
            for(auto it:adj[src]){
                int dest=it.first,wt=it.second;
                if(dist[src]+wt<dist[dest]) dist[dest]=dist[src]+wt;
            }
        }
        for(auto &i:dist){
            if(i>=1e9) i=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends