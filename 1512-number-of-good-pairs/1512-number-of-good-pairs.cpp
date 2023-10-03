class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        int ans=0;
        for(auto &[x,y]:mp) ans+=y*(y-1)/2;
        return ans;
    }
};