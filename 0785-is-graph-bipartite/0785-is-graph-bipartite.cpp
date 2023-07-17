class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        queue<int> q; 
        for(int i=0;i<n;i++){
            if(col[i]!=-1) continue;
            q.push(i); col[i]=0;
            while(!q.empty()){
                int src=q.front();q.pop();
                for(auto dest:graph[src]){
                    if(col[dest]==-1){
                        col[dest]=1-col[src]; q.push(dest);
                    }else if(col[dest]==col[src]) return false;
                }
            }
        }
        return true;
    }
};