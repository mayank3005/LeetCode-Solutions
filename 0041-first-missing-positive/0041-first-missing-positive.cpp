class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // sort(nums.begin(),nums.end());
        
        int n=nums.size();
        for(int i=0;i<n;){
            if(nums[i]<=n and nums[i]>0 and nums[i]!=nums[nums[i]-1]) 
                swap(nums[nums[i]-1],nums[i]);
            else 
                i++;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) 
                return i+1;
        }
        return n+1;
    }
};