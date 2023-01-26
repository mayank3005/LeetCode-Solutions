//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>> &adj,int src,vector<int> &vis){
        vis[src]=1;
        for(int i=0;i<adj[src].size();i++){
            bool isEdge = adj[src][i];
            if(!isEdge or vis[i]) continue;
            dfs(adj,i,vis);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(adj,i,vis),ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends