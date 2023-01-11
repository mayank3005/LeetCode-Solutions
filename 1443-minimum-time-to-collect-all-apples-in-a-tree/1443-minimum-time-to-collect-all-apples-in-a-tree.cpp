class Solution {
#define vi vector<int>
#define vvi vector<vector<int>>

private:
    bool fun(vvi &nbrs, vector<bool> &has_apple, int root,vector<bool> visited, int &ans){

        bool apple = has_apple[root];
        visited[root] = true;
        
        for(int e : nbrs[root]){
            if(!visited[e]){
                bool b = fun(nbrs, has_apple, e, visited, ans);
                if(b) ans += 2;
                apple = apple || b;
            }
        }
        
        return apple;
    }

    
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& has_apple) {
        vvi nbrs(n);
        for(vi edge : edges){
            nbrs[edge[0]].push_back(edge[1]);
            nbrs[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n , false);
        int ans = 0;
        fun(nbrs, has_apple, 0, visited, ans);

        return ans;
    }
};