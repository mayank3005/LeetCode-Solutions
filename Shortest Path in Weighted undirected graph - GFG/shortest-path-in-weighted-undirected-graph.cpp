//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        n++;
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        vector<int> par(n);
        for(int i=0;i<n;i++) par[i]=i;
        
        pq.push({0,1});
        dist[1]=0;
        
        while(!pq.empty()){
            int u=pq.top().second;int d=pq.top().first;pq.pop();
            for(auto v:adj[u]){
                if(d+v.second < dist[v.first]){
                    dist[v.first]=d+v.second;
                    par[v.first]=u;
                    pq.push({dist[v.first],v.first});
                }
            }
        }
        
        vector<int> ans;
        int i=n-1;
        while(par[i]!=i){
            ans.push_back(i);
            i=par[i];
        }
        if(ans.size()) ans.push_back(1);
        else ans.push_back(-1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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