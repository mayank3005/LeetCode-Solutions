//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int> adj[n];
	    vector<int> indeg(n,0);
	    
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
	        indeg[it.second]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<n;i++){
	        if(!indeg[i])  q.push(i);
	    }
	    vector<int> topo;
	    
	    while(!q.empty()){
	        int node=q.front();q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(!indeg[it]) q.push(it);
	        }
	    }
	    
	    
	    if(topo.size()==n) return true;
	    else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends