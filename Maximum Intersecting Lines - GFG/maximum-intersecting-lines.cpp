//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        int ans=0;
        vector<int> a,b;
        for(int i=0;i<N;i++) a.push_back(lines[i][0]),b.push_back(lines[i][1]);
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        int i=0,j=0;int curr=0;
        while(i<N and j<N){
            if(a[i]<=b[j]) i++,curr++;
            else j++,curr--;
            ans=max(ans,curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends