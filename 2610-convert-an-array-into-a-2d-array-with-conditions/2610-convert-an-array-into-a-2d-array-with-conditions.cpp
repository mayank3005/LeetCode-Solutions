class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans; ans.push_back({nums[0]}); int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) cnt++;
            else cnt=0;
            if(cnt==ans.size()) ans.push_back({nums[i]});
            else ans[cnt].push_back(nums[i]);
        }
        return ans;
    }
};