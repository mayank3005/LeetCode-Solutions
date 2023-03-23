class Solution {
public:
    void dfs(int i,vector<bool> &vis,vector<vector<int>> &adj){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n>connections.size()+1) return -1;
        int cnt=0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n,0);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt-1;
    }
};