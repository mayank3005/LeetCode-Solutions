class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),par(n,-1); int mx_idx=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 and dp[i]<dp[j]+1) {
                    dp[i]=max(dp[i],dp[j]+1);
                    par[i]=j;
                }
                if(mx_idx==-1 or dp[i]>dp[mx_idx]){
                    mx_idx=i;
                }
            }
        }
        
        int x=mx_idx; vector<int> ans;
        while(x!=-1){
            ans.push_back(nums[x]); x=par[x];
        }
        return ans;
        
    }
};