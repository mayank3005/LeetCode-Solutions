class Solution {
public:
    
    int dp[51][51][51][51];
    
    int f(int x1,int y1,int x2,int y2,vector<vector<int>> &grid){
        int n=grid.size();
        
        if(x1==n-1 and y1==n-1 and x2==n-1 and y2==n-1) return grid[x1][y1];
        
        int &ans=dp[x1][y1][x2][y2];
        
        if(ans!=-1) return ans;
        
        ans=-1e9;
        
        if(grid[x1][y1]==-1 or grid[x2][y2]==-1) return ans;
        
        int val=grid[x1][y1]+grid[x2][y2];
        
        if(x1==x2 and y1==y2) val-=grid[x1][y1];
        
        if(x1+1<n and x2+1<n) ans=max(ans,val+f(x1+1,y1,x2+1,y2,grid));
        if(x1+1<n and y2+1<n) ans=max(ans,val+f(x1+1,y1,x2,y2+1,grid));
        if(y1+1<n and x2+1<n) ans=max(ans,val+f(x1,y1+1,x2+1,y2,grid));
        if(y1+1<n and y2+1<n) ans=max(ans,val+f(x1,y1+1,x2,y2+1,grid));
        
        return ans;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        memset(dp,-1,sizeof(dp));
        
        int val=f(0,0,0,0,grid);
        
        return val<0?0:val;
        
    }
};