class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n]; dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+(i>=2?dp[i-2]:0));
        }
        return dp[n-1];
    }
};