class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        double dp[target+1];dp[0]=1;
        for(int i=1;i<=target;i++){
            dp[i]=0;
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]) dp[i]+=dp[i-nums[j]];
            }
        }
        return (int)dp[target];
    }
};