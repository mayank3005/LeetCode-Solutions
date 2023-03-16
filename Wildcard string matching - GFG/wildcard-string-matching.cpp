//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool f(int m,int n,string &a,string &b){
        if(m<0 and n>=0) return 0;
        if(n<0){
            while(m>=0 and a[m]=='*') m--;
            return m<0;
        }
        
        if(n>=0 and (a[m]==b[n] or a[m]=='?')) return f(m-1,n-1,a,b);
        else if(a[m]=='*') return f(m-1,n,a,b) or f(m-1,n-1,a,b) or f(m,n-1,a,b);
        return false;
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        return f(wild.size()-1,pattern.size()-1,wild,pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends