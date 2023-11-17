class Solution {
public:
    int minPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> sum;
    for(int i=0;i<nums.size()/2;i++){
        sum.push_back(nums[i]+nums[nums.size()-1-i]);
    }
    return *max_element(sum.begin(),sum.end());
    }
};