//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st; int res=0; vector<int> ans(s.length(),0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(!st.empty()){
                ans[i]=i-st.top()+1 + (st.top()?ans[st.top()-1]:0);
                st.pop();
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends