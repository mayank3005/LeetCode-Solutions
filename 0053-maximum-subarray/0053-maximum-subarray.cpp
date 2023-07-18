class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-1e9,curr=0;
        for(auto i:nums){
            curr+=i;
            ans=max(ans,curr);
            curr=max(0,curr);
        }
        return ans;
    }
};