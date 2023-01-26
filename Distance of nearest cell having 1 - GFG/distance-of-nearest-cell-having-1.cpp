//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    class Node{
        public:
        int x,y,dist;
    };
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    queue<Node> q;
	    for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++){
	        if(grid[i][j]) q.push({i,j,0});
	    }
	    
	    int delrow[] = {0,0,-1,1};
	    int delcol[] = {1,-1,0,0};
	    while(!q.empty()){
	        Node node=q.front();q.pop();
	        for(int i=0;i<4;i++){
	                int dx=node.x+delrow[i],dy=node.y+delcol[i];
	                if(dx>=n or dx<0 or dy>=m or dy<0 or grid[dx][dy]) continue;
	                grid[dx][dy]=1;
	                ans[dx][dy]=node.dist+1;
	                q.push({dx,dy,node.dist+1});
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends