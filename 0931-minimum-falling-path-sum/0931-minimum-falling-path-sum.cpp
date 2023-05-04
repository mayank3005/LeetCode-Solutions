class Solution {
public:
    // dp[i][j] --> min sum of falling path from ith row to last row
    int minFallingPathSum(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int one,two,three; one=two=three=1e8;
                if(j) one=v[i+1][j-1];
                if(j<n-1) three=v[i+1][j+1];
                v[i][j]+=min(v[i+1][j],min(one,three));
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++) ans=min(ans,v[0][i]);
        return ans;
    }
};