#define pii pair<long long,int>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<pii> adj[n];
        for(auto &i:roads){
            adj[i[0]].push_back({i[1],i[2]}); adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<long long> dist(n,1e18); vector<int> val(n,1);
        dist[0]=0; pq.push({0LL,0});
        while(!pq.empty()){
            long long dd=pq.top().first;int u=pq.top().second; pq.pop();
            for(auto &pp:adj[u]){
                int v=pp.first,w=pp.second;
                if(dd+w==dist[v]){
                    val[v]=(val[v]+val[u])%mod;
                }else if(dd+w<dist[v]){
                    dist[v]=dd+w; val[v]=val[u]; pq.push({dist[v],v});
                }
            }
        }
        return val[n-1];
    }
};