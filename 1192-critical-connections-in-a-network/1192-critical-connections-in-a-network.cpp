class Solution {
public:
    int timer;
    void dfs(int src,int par,vector<int> adj[],vector<int> &vis,vector<vector<int>> &res,
            vector<int> &low,vector<int> &insTime){
        
        vis[src]=1;
        insTime[src]=low[src]=++timer;
        
        for(int dest:adj[src]){
            if(dest==par) continue;
            if(!vis[dest]){
                dfs(dest,src,adj,vis,res,low,insTime);
                if(low[dest]>insTime[src])
                    res.push_back({src,dest});
            }
            low[src]=min(low[src],low[dest]);
        }      
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        timer=0;
        
        vector<int> adj[n+1];
        for(auto &pr:connections){
            adj[pr[0]].push_back(pr[1]);
            adj[pr[1]].push_back(pr[0]);
        }
        
        vector<vector<int>> res;
        vector<int> low(n+1,-1),insTime(n+1,-1),vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]) dfs(1,-1,adj,vis,res,low,insTime);
        }
        return res;
    }
};