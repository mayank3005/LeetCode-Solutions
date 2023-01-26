//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int delrow[4] = {0,0,1,-1};
    int delcol[4] = {1,-1,0,0};
    void solve(vector<vector<int>> &ans,int sr,int sc,int ic,int nc){
        int m=ans.size();int n=ans[0].size();
        ans[sr][sc]=nc;
        for(int x=0;x<=3;x++){
            int i=sr+delrow[x],j=sc+delcol[x];
                if(i>=m or i<0 or j>=n or j<0 or ans[i][j]!=ic) continue;
                solve(ans,i,j,ic,nc);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int ic=image[sr][sc];
        vector<vector<int>> ans = image;
        if(ic==newColor) return ans;
        solve(ans,sr,sc,ic,newColor);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends