class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> ans;
        for(int i = 0; i < size(nums); i++) 
            if((i && nums[i] == nums[i-1]) || (i+1 < size(nums) && nums[i] == nums[i+1])) continue;
            else ans.push_back(nums[i]);
        return ans;
    }
};