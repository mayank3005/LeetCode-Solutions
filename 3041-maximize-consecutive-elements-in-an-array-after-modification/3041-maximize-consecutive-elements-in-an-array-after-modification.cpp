class Solution {
public:
    
    // int f(int i,int x,vector<int> &nums){
    //     int n=nums.size();
    //     if(i==n) return 0;
    //     int ans=f(i+1,x,nums);
    //     if(nums[i]==x or num[i]+1==x) 
    //         ans=max(1+f(i+1,x+1,nums),ans);
    //     return ans;
    // }
    
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size(); sort(nums.begin(),nums.end());
        int mx=1e6+2;
        vector<int> dp(mx,0);
        
        for(int i=n-1;i>=0;i--){
                // dp[i][j]=dp[i+1][j];
                // if(nums[i]==j or nums[i]+1==j) dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                dp[nums[i]]=max(dp[nums[i]],1+dp[nums[i]+1]);
                dp[nums[i]+1]=max(dp[nums[i]+1],1+dp[nums[i]+2]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};