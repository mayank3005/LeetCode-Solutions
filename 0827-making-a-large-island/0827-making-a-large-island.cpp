class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
    
    int sz(int x){return sizes[x];}
    
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        DisjointSets st(m*n);
        
        auto isValid = [m,n,&grid](int x,int y){
            if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==0) return false;
            return true;
        };
        
        int dx[5]={0,1,0,-1,0};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int newi=i+dx[k],newj=j+dx[k+1];
                    int curr=i*n+j; int adj=newi*n+newj;
                    if(isValid(newi,newj)) st.unite(curr,adj);
                }
            }
        }
        
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {ans=max(ans,st.sz(i*n+j));continue;} 
                
                set<int> ss;
                
                for(int k=0;k<4;k++){
                    int newi=i+dx[k],newj=j+dx[k+1];
                    int curr=i*n+j; int adj=newi*n+newj;
                    if(isValid(newi,newj)){
                        ss.insert(st.find(adj));
                    }
                }
                
                int curr=1;
                for(auto x:ss){
                    curr+=st.sz(x);
                }
                
                ans=max(ans,curr);
                
            }
        }
        
        return ans;
    }
};










