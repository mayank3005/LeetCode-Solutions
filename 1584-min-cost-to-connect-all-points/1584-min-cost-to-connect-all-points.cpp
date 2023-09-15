class Solution {
    class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }   
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void Union(int u,int v){
        u=findParent(u),v=findParent(v);
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
};
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj.push_back({abs(points[i][1]-points[j][1])+abs(points[i][0]-points[j][0]),{i,j}});
            }
        }
        DisjointSet ds(n+1); int ans=0;
        sort(adj.begin(),adj.end());
        for(int i=0;i<adj.size();i++){
            int wt=adj[i].first;int a=adj[i].second.first,b=adj[i].second.second;
            a=ds.findParent(a),b=ds.findParent(b);
            if(a!=b){
                ds.Union(a,b);
                ans+=wt;
            }
        }
        return ans;
    }
};