//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,int>
#define ppii pair<int,pair<int,int>>

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        vector<pii> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<ppii> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            ppii node = q.front();q.pop();
            int k=node.first,u=node.second.first,d=node.second.second;
            if(k>K) continue;
            for(auto it:adj[u]){
                int v=it.first,wt=it.second;
                if(d+wt<dist[v] and k<=K){
                    q.push({k+1,{v,d+wt}});
                    dist[v]=d+wt;
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        else return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends