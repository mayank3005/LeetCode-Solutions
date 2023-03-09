class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();int curr=0;
        for(int i=0;i<n;i++){
            if(curr==tot-curr-nums[i]) return i;
            curr+=nums[i];
        }
        return -1;
    }
};