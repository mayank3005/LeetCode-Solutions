#define ppi pair<int,int>
#define tti tuple<int,int,int>
#define vi vector<int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<ppi> adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        // vector<bool> vis(n,false);
        
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        pq.push({0,src,0});   // {cost,city,stops}
    
        int check=0;
        
        while(!pq.empty()){
            // auto [cost,u,stops]=pq.top();
            if(check>1500) break;
            
            int cost=pq.top()[0];
            int u=pq.top()[1];
            int stops=pq.top()[2];
            pq.pop();
            
            if(u==dst) return cost;
            if(stops>k) continue;
            for(auto v:adj[u]){
                auto [x,y]=v;
                pq.push({cost+y,x,stops+1});
            }
            check++;
        }
        
        return -1;
        
    }
};