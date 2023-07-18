class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2) return false;
        int dp[n][tot/2+1];
        for(int i=0;i<=tot/2;i++) dp[0][i]=0;
        dp[0][0]=1; if(nums[0]<=tot/2) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=tot/2;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i]) dp[i][j]|=dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][tot/2];
    }
};