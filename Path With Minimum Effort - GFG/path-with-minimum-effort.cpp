//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,int>
#define ppii pair<int,pair<int,int>>
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        
        priority_queue<ppii,vector<ppii>,greater<ppii>> pq;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> ans(m,vector<int>(n,1e9));
        
        ans[0][0]=0;
        pq.push({0,{0,0}});
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        while(!pq.empty()){
            ppii node=pq.top();pq.pop();
            int cd=node.first,x=node.second.first,y=node.second.second;
            
            if(x==m-1 and y==n-1) return cd;
            
            for(int i=0;i<4;i++){
                int newx=x+dx[i],newy=y+dy[i];
                if(newx<0 or newx>=m or newy<0 or newy>=n) continue;
                int diff = max(cd,abs(heights[x][y]-heights[newx][newy]));
                if(diff<ans[newx][newy]){
                    ans[newx][newy]=diff;
                    pq.push({diff,{newx,newy}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends