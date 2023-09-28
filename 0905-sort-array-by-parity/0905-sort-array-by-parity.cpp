class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            while(i<n and (nums[i]&1)==0) i++;
            while(j>0 and (nums[j]&1)!=0) j--;
            if(i<j) swap(nums[i],nums[j]);
            // i++,j--;
        }
        return nums;
    }
};