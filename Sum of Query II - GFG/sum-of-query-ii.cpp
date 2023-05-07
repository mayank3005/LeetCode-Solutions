//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

const int N = 1e5 + 5;
int bit[N];
class Solution{
    int query(int x) {
    	int ans = 0;
    	while (x > 0) {ans += bit[x]; x -= (x & -x);}
    	return ans;
    }
    
    void update(int x, int val) {
    	while (x < N) {
    		bit[x] += val; x += (x & -x);
    	}
    }
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        memset(bit,0,sizeof(bit));
        for (int i = 1; i <= n; i++) {update(i, arr[i-1]);}
        vector<int> ans;
        for(int i=0;i<2*q;i+=2){
            int l=queries[i],r=queries[i+1];
            ans.push_back(query(r)-query(l-1));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends