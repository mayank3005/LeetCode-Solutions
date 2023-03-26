class Solution {
public:
    
    void dfs(int src,vector<int> &edges,vector<int> &vis
             ,vector<int> &dfsvis,vector<int> &dist,int &ans,int distance){

        if(src==-1) return;
        if(!vis[src]){
            vis[src]=1;dfsvis[src]=1;dist[src]=distance;
            dfs(edges[src],edges,vis,dfsvis,dist,ans,distance+1);
        }else if(dfsvis[src]){
            ans=max(ans,distance-dist[src]);
        }
        dfsvis[src]=0;
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();
        vector<int> vis(n,0),dfsvis(n,0),dist(n,-1);
        
        int ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,edges,vis,dfsvis,dist,ans,0);
        }
        return ans;
    }
};