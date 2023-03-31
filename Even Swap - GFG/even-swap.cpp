//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            multiset<int,greater<int>> st; vector<int> ans;
            int flag=0;
            for(auto i:a){
                if(i%2 != flag){
                    while(!st.empty()){
                        ans.push_back(*st.begin());st.erase(st.begin());
                    }
                    flag=1-flag;
                }
                st.insert(i);
            }
            while(!st.empty()){
                ans.push_back(*st.begin());st.erase(st.begin());
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends