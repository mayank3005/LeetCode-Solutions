class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1) continue;
                int val1=INT_MAX,val2=INT_MAX;
                if(i!=m-1) val1=grid[i+1][j];
                if(j!=n-1) val2=grid[i][j+1];
                grid[i][j]+=min(val1,val2);
            }
        }
        return grid[0][0];
    }
};