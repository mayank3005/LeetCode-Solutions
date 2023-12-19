class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1; int sum=0; int ans=0;
        for(auto i:nums){
            sum+=i;
            if(mp.count(sum-k)>0) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};