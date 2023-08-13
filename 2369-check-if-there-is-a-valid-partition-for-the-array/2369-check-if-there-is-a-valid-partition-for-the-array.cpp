class Solution {
public:
    
    int dp[100002];
    
    int f(int k,vector<int> &nums){
        
        int n=nums.size();
        
        if(k==n) return 1;
        
        int &ans=dp[k];
        if(ans!=-1) return ans;
        
        int a=k+1,b=k+2;
        
        if(a<n and nums[a]==nums[k] and f(k+2,nums)) ans=1; 
        else if(b<n and nums[k]==nums[a] and nums[a]==nums[b] and f(k+3,nums)) ans=1;
        else if(b<n and nums[k]==nums[a]-1 and nums[a]==nums[b]-1 and f(k+3,nums)) ans=1;
        else ans=0;
        
        return ans;
    }
    
    bool validPartition(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
        
    }
};