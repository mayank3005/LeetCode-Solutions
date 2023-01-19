class Solution {
public:
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
//         in mp storing remainder->freq pair
    mp[0]=1;
    int sum=0,cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        int rem=sum%k;
        if(rem<0)
            rem+=k;
        mp[rem]++;
        cnt+=mp[rem]-1;
    }
    return cnt;
}
};