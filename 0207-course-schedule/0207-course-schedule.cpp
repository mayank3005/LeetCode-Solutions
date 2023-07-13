class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n]; vector<int> indeg(n,0);
        for(auto &v:pre){
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }
        queue<int> q; int temp=0;
        for(int i=0;i<n;i++){
            if(!indeg[i]) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            temp++;
            for(auto v:adj[u]){
                indeg[v]--;
                if(!indeg[v])
                    q.push(v);
            }
        }
        return temp==n;
    }
};