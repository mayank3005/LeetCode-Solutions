class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=-1e9; int pref=1,suff=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!pref) pref=1;
            if(!suff) suff=1;
            pref*=nums[i],suff*=nums[n-i-1];
            ans=max(ans,max(pref,suff));
        }
        return ans;
    }
};