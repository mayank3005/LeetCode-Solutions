class Solution {
public:
    int demand[100];
    vector<int> adj[100];

    // fill demand in terms of how many times current node will be vistited in all trips
    int isInPath(int u,int dest,int p = -1){

        if(u == dest) {
            demand[dest]++;
            return 1;
        }
        for(auto v: adj[u]) {
            if(v == p) continue;

            if(isInPath(v,dest,u)) {
                demand[u]++;
                return 1;
            }
        }

        return 0;
    }
    // Pair represents: minimum sum with {current Node halved, current node not halved}
    // Observations: If you halve the current node then you cannot halve its adjcent)
    pair<int,int> minNonAdjecentPath(int u,int p, vector<int>& price) {
        int considerCurrent = (price[u]/2) * (demand[u])   ;
        int dontConsiderCurrent = price[u] * demand[u];

        for(auto v: adj[u]){
            if(v == p)continue;

            pair<int,int> childAns = minNonAdjecentPath(v,u,price);
            // Take minimum of both consider and not consider case of childs
            dontConsiderCurrent += min(childAns.first, childAns.second);

            // You can only take values where child node is not halved
            considerCurrent += childAns.second;
        }
        // return current answer
        return {considerCurrent, dontConsiderCurrent};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // cleanup
        memset(demand,0, sizeof demand);
        for(int i=0;i<n;i++){
            adj[i].clear();
        }

        // graph formation
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // fill demand for nodes
        for(auto trip: trips) {
            int u = trip[0];
            int v = trip[1];

            isInPath(u,v);
        }


        pair<int,int> ans = minNonAdjecentPath(0,-1,price);

        return min(ans.first, ans.second);


    }
};