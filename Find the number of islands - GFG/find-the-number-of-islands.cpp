//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int dx[8]={0,0,1,1,1,-1,-1,-1};
    int dy[8]={1,-1,0,1,-1,0,1,-1};
  
    // Function to find the number of islands.
    void dfs(int x,int y,vector<vector<char>> &grid,vector<vector<int>> &vis){
        int n=grid.size(),m=grid[0].size();
        if(x>=n or x<0 or y>=m or y<0 or vis[x][y] or grid[x][y]!='1') return;
        vis[x][y]=1;
        for(int i=0;i<8;i++){
            int xx=x+dx[i],yy=y+dy[i];
            dfs(xx,yy,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1')
                    dfs(i,j,grid,vis),ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends