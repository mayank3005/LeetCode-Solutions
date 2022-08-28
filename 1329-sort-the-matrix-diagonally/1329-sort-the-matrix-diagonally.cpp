class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m=mat.size(),n=mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n));
        
        for(int diff=-1*n;diff<=m;diff++){
            vector<int> temp;
            for(int i=0;i<m;i++){
                int j=i-diff;
                // if(j<n and j>=0) cout<<i<<" "<<j<<endl;
                if(j<n and j>=0) temp.push_back(mat[i][j]); 
            }
            // cout<<endl;
            sort(temp.begin(),temp.end());
            int k=0;
            for(int i=0;i<m;i++){
                int j=i-diff;
                if(j<n and j>=0) ans[i][j]=temp[k++];
            }
        }
        return ans;
    }
};