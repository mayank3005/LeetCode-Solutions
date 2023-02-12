class Solution {
public:
    
    long long ans=0;
    
    int dfs(int src,int par,vector<int> adj[],int seats){
        
        int child=0;
        for(auto it:adj[src]){
            if(it==par) continue;
            child+=dfs(it,src,adj,seats);
        }
        child++;
        if(src) ans+=ceil(1.0*child/seats);
        return child;
        
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int> adj[n+1];
        
        ans=0;
        
        for(auto &v:roads){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        dfs(0,-1,adj,seats);
        return ans;
        
    }
};