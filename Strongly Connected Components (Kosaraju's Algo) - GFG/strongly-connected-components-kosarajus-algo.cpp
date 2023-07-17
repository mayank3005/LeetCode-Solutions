//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    vector<int> order;
	void dfs(int src,vector<vector<int>> &adj,vector<int> &vis){
	    vis[src]=1;
	    for(auto dest:adj[src]){
	        if(vis[dest]) continue;
	        dfs(dest,adj,vis);
	    }
	    order.push_back(src);
	}
	void dfs2(int src,vector<int> adj[],vector<int> &vis){
	    vis[src]=1;
	    for(auto dest:adj[src]){
	        if(vis[dest]) continue;
	        dfs2(dest,adj,vis);
	    }
	}
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,adj,vis);
        }
        
        reverse(order.begin(),order.end());
        
        vector<int> rev[n];
        for(int i=0;i<n;i++){
            for(auto dest:adj[i]){
                rev[dest].push_back(i);
            }
        }
        
        int ans=0; for(auto &i:vis) i=0;
        for(int i:order){
            if(vis[i]) continue;
            ans++;
            dfs2(i,rev,vis);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends