class Solution {
public:
    int ret = 1;

    int dfs(vector<vector<int>> &adj, string &s, int node){
        int m1 = 0, m2 = 0;
        for(auto z:adj[node]){
            auto t = dfs(adj, s, z);
            if(s[z] != s[node]){
                if(t >= m1)  {m2 = m1; m1 = t;}
                else m2 = max(m2, t);
            }
        }
        ret = max(ret, m1+m2+1);
        return m1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size());
        for(int i=1;i<parent.size();i++)    adj[parent[i]].push_back(i);
        dfs(adj, s, 0);
        return ret;
    }
};