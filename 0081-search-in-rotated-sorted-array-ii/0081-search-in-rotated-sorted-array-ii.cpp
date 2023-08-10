class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[i] and nums[mid]==nums[j]){
                i++,j--;
            }
            else if(nums[i]<=nums[mid]){
                if(nums[i]<=target and nums[mid]>=target)
                    j=mid-1;
                else
                    i=mid+1;
            }else{
                if(nums[mid]<=target and nums[j]>=target)
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return false;        
    }
};