class Solution {
public:
    int dp[301][301];
    int f(int i,int j,vector<int> &nums){
        if(i>j) return 0;
        int &ans=dp[i][j];
        if(ans!=-1) return ans;
        int maxi=0;
        for(int k=i;k<=j;k++){
            maxi=max(maxi,nums[k]*nums[i-1]*nums[j+1]+f(i,k-1,nums)+f(k+1,j,nums));
        }
        return ans=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1); nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        return f(1,nums.size()-2,nums);
    }
};