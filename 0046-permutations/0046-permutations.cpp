class Solution {
public:
    void f(int idx,vector<int> &nums,vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back(nums); return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            f(idx+1,nums,res);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        f(0,nums,res);
        return res;
    }
};