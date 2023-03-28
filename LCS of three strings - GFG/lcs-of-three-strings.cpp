//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int dp[21][21][21];

int f(string &a,string &b,string &c,int x,int y,int z){
    if(x==-1 or y==-1 or z==-1) return 0;
    int &ans=dp[x][y][z];
    if(ans!=-1) return ans;
    if(a[x]==b[y] and b[y]==c[z]) return ans=1+f(a,b,c,x-1,y-1,z-1);
    return ans=max({f(a,b,c,x-1,y,z),f(a,b,c,x,y-1,z),f(a,b,c,x,y,z-1)});
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp,-1,sizeof(dp));
    return f(A,B,C,n1-1,n2-1,n3-1);
}