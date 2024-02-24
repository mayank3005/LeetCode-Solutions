class Solution {
    
class DisjointSets {
  public:
	vector<int> parents;
    vector<int> sizes;
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
};

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f) {
        DisjointSets dsu(n+1);
        sort(m.begin(),m.end(),[](vector<int> &a,vector<int> &b){
            return a[2]<b[2];
        }); 
        dsu.unite(0,f);
        int i=0,j=0; int sz=m.size();
        while(i<sz){
            j=i;
            while(j<sz and m[j][2]==m[i][2]){
                dsu.unite(m[j][0],m[j][1]);
                j++;
            }
            j=i;
            while(j<sz and m[j][2]==m[i][2]){
                if(dsu.connected(m[j][0],0)==false){
                    dsu.parents[m[j][0]]=m[j][0];
                    dsu.parents[m[j][1]]=m[j][1];
                    dsu.sizes[m[j][0]]=1;dsu.sizes[m[j][1]]=1;
                } 
                j++;
            }
            i=j;
        }
        vector<int> ans;
        for(int i=0;i<=n;i++){
            if(dsu.connected(i,0)) ans.push_back(i);
        }
        return ans;
    }
};


