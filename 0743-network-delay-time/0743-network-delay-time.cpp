#define pii pair<int,int> 

class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> adj[n];
        for(auto i:times){
            adj[i[0]-1].push_back({i[1]-1,i[2]}); 
        }
        vector<int> dist(n,1e9);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k-1}); dist[k-1]=0;
        while(!pq.empty()){
            int dd=pq.top().first,u=pq.top().second; pq.pop();
            for(pii &pp:adj[u]){
                int v=pp.first,w=pp.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w; pq.push({dist[v],v});
                }
            }
        }
        int mx=*max_element(dist.begin(),dist.end());
        return mx==1e9?-1:mx;
    }
};