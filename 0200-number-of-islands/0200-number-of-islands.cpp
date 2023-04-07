class Solution {
public:
    int dx[5]={0,-1,0,1,0};
    void dfs(int x,int y,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int m=grid.size(),n=grid[0].size();
        if(x>m-1 or y>n-1 or x<0 or y<0 or grid[x][y]=='0' or vis[x][y]) return;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dx[i+1],vis,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0)); int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and !vis[i][j])
                    ans++,dfs(i,j,vis,grid);
            }
        }
        return ans;
    }
};