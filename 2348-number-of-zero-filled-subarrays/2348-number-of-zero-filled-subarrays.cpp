class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0,ans=0;
        for(auto i:nums){
            if(!i) c++;
            else{
                ans+=(c*(c+1)/2);
                c=0;
            }
        }
        ans+=(c*(c+1)/2);
        return ans;
    }
};