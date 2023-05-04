class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        v[0][0]=(v[0][0]==0);
        for(int i=1;i<n;i++){
            if(v[0][i]) v[0][i]=0;
            else v[0][i]=v[0][i-1];
        }
        for(int j=1;j<m;j++){
            if(v[j][0]) v[j][0]=0;
            else v[j][0]=v[j-1][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(v[i][j]) v[i][j]=0;
                else{
                    v[i][j]+=v[i-1][j]+v[i][j-1];
                }
            }
        }
        return v[m-1][n-1];
    }
};