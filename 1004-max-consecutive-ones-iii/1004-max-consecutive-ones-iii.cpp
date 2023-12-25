class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0; int ans=0;int n=nums.size(); int cnt=0;
        while(j<n){
            cnt+=(bool)(nums[j]==0);
            while(i<=j and cnt>k) cnt-=(bool)(nums[i++]==0);
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};