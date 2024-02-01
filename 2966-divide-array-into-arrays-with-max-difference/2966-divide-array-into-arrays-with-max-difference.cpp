class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end()); int n=nums.size();
        for(int i=0;i<n;i+=3){
            ans.push_back(vector<int>(nums.begin()+i,nums.begin()+i+3));
            if(ans.back()[2]-ans.back()[0]>k) return {};
        }
        return ans;
    }
};