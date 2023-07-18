class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(auto i:nums){
            auto it=lower_bound(v.begin(),v.end(),i)-v.begin();
            if(it>=v.size()) v.push_back(i);
            else v[it]=i;
        }
        return v.size();
    }
};