//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    class Node{
        public:
        int dist,x,y;
    };
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        int m=grid.size(),n=grid[0].size();
        
        if(source==destination) return 0;
        
        vector<vector<int>> ans(m,vector<int>(n,1e9));
        queue<Node> q;
        q.push({0,source.first,source.second});
        ans[source.first][source.second]=0;
        
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        
        while(!q.empty()){
            Node node = q.front();q.pop();
            for(int i=0;i<4;i++){
                int newr=node.x+dx[i],newc=node.y+dy[i];
                if(newr<0 or newr>=m or newc<0 or newc>=n or !grid[newr][newc]) continue;
                if(ans[newr][newc]>node.dist+1){
                    ans[newr][newc]=node.dist+1;
                    q.push({node.dist+1,newr,newc});
                    if(newr==destination.first and newc==destination.second) return node.dist+1;
                }
            }
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends