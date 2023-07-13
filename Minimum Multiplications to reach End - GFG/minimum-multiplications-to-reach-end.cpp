//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<int> q;
        q.push(start); int ans=0; 
        vector<int> vis(mod+1,0);vis[start]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int val=q.front();q.pop();
                if(val==end) return ans;
                for(auto i:arr){
                    int num=val*i%mod;
                    if(vis[num]) continue;
                    vis[num]=1;
                    q.push(num);
                }
            }
            ++ans;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends