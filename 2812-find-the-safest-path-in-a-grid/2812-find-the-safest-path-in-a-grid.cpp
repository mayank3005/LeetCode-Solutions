class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(); vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> dist(n,vector<int>(n,1e9)); queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) {dist[i][j]=0,q.push({0,{i,j}});vis[i][j]=1;}
            }
        }
        vector<int> dd={0,1,0,-1,0};
        while(!q.empty()){
            int d=q.front().first,a=q.front().second.first,b=q.front().second.second; q.pop();
            for(int i=1;i<5;i++){
                int x=a+dd[i-1],y=b+dd[i];
                if(x>=n or x<0 or y>=n or y<0 or dist[x][y]<d+1 or vis[x][y]) continue;
                q.push({d+1,{x,y}});
                dist[x][y]=d+1; vis[x][y]=1;
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) vis[i][j]=0;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({dist[0][0],{0,0}}); 
        vis[0][0]=1;
        while(!pq.empty()){
            int ans=pq.top().first,a=pq.top().second.first,b=pq.top().second.second;pq.pop();
            if(a==n-1 and b==n-1) return ans;
            for(int i=1;i<5;i++){
                int x=a+dd[i-1],y=b+dd[i];
                if(x>=n or x<0 or y>=n or y<0 or vis[x][y]) continue;
                pq.push({min(dist[x][y],ans),{x,y}});
                vis[x][y]=1;
            }
        }
        return 0;
    }
};