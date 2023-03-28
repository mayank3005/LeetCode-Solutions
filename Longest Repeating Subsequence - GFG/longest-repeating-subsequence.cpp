//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int dp[1001][1001];
	    int f(int i,int j,string &str){
	        int n=str.length();
	        if(i==n or j==n) return 0;
	        
	        int &ans=dp[i][j];
	        if(ans!=-1) return ans;
	        
	        if(str[i]==str[j] and i!=j) return ans=1+f(i+1,j+1,str);
	        return ans=max(f(i,j+1,str),f(i+1,j,str));
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    memset(dp,-1,sizeof(dp));
		    return f(0,0,str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends