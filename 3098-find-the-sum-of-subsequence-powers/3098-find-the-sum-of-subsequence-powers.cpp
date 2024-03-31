class Solution {
public:
    int mod=1e9+7;
    int dp[51][52][51];
    int f(int i,int last_idx,int k,int d,int n,vector<int> &nums){
        if(i==n) return (k==0);
        int &ans=dp[i][last_idx+1][k];
        if(ans!=-1) return ans;
        ans=f(i+1,last_idx,k,d,n,nums);
        if(k>0 and (last_idx==-1 or abs(nums[i]-nums[last_idx])>=d)) ans=(ans+f(i+1,i,k-1,d,n,nums))%mod;
        return ans;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());
        set<int> st; int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                st.insert(abs(nums[j]-nums[i]));
            }
        }
        int prev=0;
        
        vector<int> diff(st.begin(),st.end());
        
        for(int i=diff.size()-1;i>=0;i--){
            memset(dp,-1,sizeof(dp)); 
            int d=diff[i];
            int val=f(0,-1,k,d,n,nums);
            ans=(ans+((val-prev+mod)%mod*1LL*d)%mod)%mod;
            prev=val;
        }
        return ans;
    }
};