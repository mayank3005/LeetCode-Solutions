class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n;
        while(i<j-1){
            int mid=(i+j)/2;
            if(nums[mid]>target) j=mid;
            else i=mid;
        }
        if(nums[i]==target) return i;
        return -1;
    }
};