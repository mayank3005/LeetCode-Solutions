class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> mx(n,0);
        mx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mx[i]=max(mx[i+1],nums[i]);
        }
        
        int mn=nums[0];
        
        for(int i=1;i<n-1;i++){
            if(mn<nums[i] and mx[i+1]>nums[i])
                return true;
            mn=min(mn,nums[i]);
        }
        return false;
    }
};