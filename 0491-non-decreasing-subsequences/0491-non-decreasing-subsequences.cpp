class Solution {
public:
    void util(vector<int>& nums, int i, set<vector<int>> &s, vector<int> &temp){
        if(i==nums.size()){
            if(temp.size()>1)
                s.insert(temp);
            return;
        }
        if(temp.empty() or temp.back()<=nums[i]){
            temp.push_back(nums[i]);
            util(nums,i+1,s,temp);
            temp.pop_back();  //BackTrackking to the previous state
        }
        util(nums,i+1,s,temp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        util(nums,0,s,temp);
        return vector<vector<int>>(s.begin(),s.end());
    }
};