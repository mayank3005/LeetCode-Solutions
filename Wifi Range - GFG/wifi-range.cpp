//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        vector<vector<int>>val;
        for(int i=0;i<N;i++){
            if(S[i] == '1'){
                int a = max(0, i-X);
                int b = min(N-1, i+X);
                val.push_back({a, b});
            }
        }
        pair<int, int>p;
        p = {val[0][0], val[0][1]};
        for(int i=1;i<val.size();i++){
            if((p.second >= val[i][0]) || (val[i][0] == p.second + 1)){
                p.second = val[i][1];
            }
            else{
                return false;
            }
        }
        if(p.first == 0 && p.second == S.size()-1) return true;
        else return false;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends