class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        if(k==1) return true;
        for(int i=0;i<n;i++){
            if(i>=k) sum-=nums[i-k];
            nums[i]-=sum;
            sum+=nums[i];
            if(nums[i]<0) return false;
        }
        return nums[n-1]==0;
    }
};