//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> ans; int maxCol;
public:

    bool check(vector<int> &curr,int val){
        int n=curr.size();
        for(int i=n-1;i>=0;i--){
            int x=n-i;
            if(curr[i]==val or curr[i]==val-x or curr[i]==val+x) return false;
        }
        return true;
    }

    void f(int col,vector<int> &curr){
        if(col==maxCol){
            ans.push_back(curr);
            return;
        }
        int maxRow=maxCol;
        for(int i=0;i<maxRow;i++){
            if(check(curr,i+1)){
                curr.push_back(i+1);
                f(col+1,curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        maxCol=n;
        ans.clear();vector<int> curr;
        f(0,curr);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends