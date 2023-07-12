class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size(); vector<int> ans;
        vector<vector<int>> rev(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                rev[j].push_back(i);
            }
        }
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j:rev[i]) indeg[j]++;
        }
        queue<int> q; 
        for(int i=0;i<n;i++){
            if(!indeg[i]) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            ans.push_back(u);
            for(auto v:rev[u]){
                indeg[v]--;
                if(!indeg[v]) q.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};