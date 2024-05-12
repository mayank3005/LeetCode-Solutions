class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        int sz=3;
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++){
            vector<int> temp;
            for(int j=0;j<n-2;j++){
                int val=-1e9;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        val=max(val,grid[i+x][j+y]);
                    }
                }
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};