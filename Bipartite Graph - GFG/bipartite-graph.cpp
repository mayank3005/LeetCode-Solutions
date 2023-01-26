//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool bfs(int src,vector<int> adj[],vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src]=0;
        while(!q.empty()){
            int u=q.front().first;int cc=q.front().second;
            q.pop();
            for(auto it:adj[u]){
                if(vis[it]==-1){
                    vis[it]=1-cc;
                    q.push({it,vis[it]});
                }else if(vis[it]==cc) return false;
            }
        }
        return true;
    }

	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> vis(n,-1);
	    for(int i=0;i<n;i++){
	        if(vis[i]==-1) 
	            if(!bfs(i,adj,vis)) return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends