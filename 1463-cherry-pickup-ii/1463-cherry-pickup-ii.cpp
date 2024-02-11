const int inf=-1e9;
int dp[71][71][71]; int m,n; vector<vector<int>> v;
int dx[3]={-1,0,1};

class Solution {
public:
    bool check(int x,int y){
        return (x>=0 and y>=0 and x<n and y<n);
    }
        
    int f(int i,int j1,int j2){
        if(i==m) return 0;
        int &ans=dp[i][j1][j2];
        if(ans!=-1) return ans;
        
        int temp=v[i][j1];
        if(j1!=j2) temp+=v[i][j2];
        
        int curr=0;
        
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                int x=j1+dx[j],y=j2+dx[k];
                if(check(x,y)){
                    curr=max(curr,f(i+1,x,y));    
                }
            }
        }
        
        return ans=temp+curr;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m=grid.size();n=grid[0].size(); v=grid;
        return f(0,0,n-1);
    }
};