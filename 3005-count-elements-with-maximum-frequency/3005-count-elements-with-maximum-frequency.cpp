class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp; int mx=0;
        for(auto i:nums){
            mp[i]++;
            mx=max(mx,mp[i]);
        }
        int ans=0;
        for(auto &[_,x]:mp){
            if(x==mx) ans+=x;
        }
        return ans;
    }
};