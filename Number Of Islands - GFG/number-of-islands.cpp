//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }   
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void Union(int u,int v){
        u=findParent(u),v=findParent(v);
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        DisjointSet ds(n*m);
        
        vector<int> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cnt=0;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(auto it:operators){
            int r=it[0],c=it[1];
            if(vis[r][c]) {ans.push_back(cnt);continue;}
            vis[r][c]=1;
            cnt++;
            
            for(int i=0;i<4;i++){
                int newr=r+dx[i],newc=c+dy[i];
                if(newr<0 or newr>=n or newc<0 or newc>=m) continue;
                if(vis[newr][newc]){
                    int adjnum = m*newr+newc;
                    int curr = m*r+c;
                    if(ds.findParent(adjnum)!=ds.findParent(curr)){
                        ds.Union(adjnum,curr);
                        cnt--;
                    }
                }
            }
            
            
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends