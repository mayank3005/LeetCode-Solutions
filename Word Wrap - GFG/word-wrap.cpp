//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[1001];
    int f(int idx,int n,vector<int> &nums,int k){
        if(idx>=n-1) return 0;
        int &res=dp[idx];
        if(res!=-1) return res;
        int ans=INT_MAX,curr=0;
        for(int i=idx;i<n;i++){
            if(i==idx) curr+=nums[i];
            else curr+=(1+nums[i]);
            if(curr>k) break;
            if(i!=n-1) ans=min(ans,(k-curr)*(k-curr)+f(i+1,n,nums,k));
            else ans=min(ans,0);
        }
        return res=ans;
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp,-1,sizeof(dp));
        return f(0,nums.size(),nums,k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends