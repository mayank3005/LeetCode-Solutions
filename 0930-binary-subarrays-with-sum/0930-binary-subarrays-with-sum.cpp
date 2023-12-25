class Solution {
public:
    int atMost(vector<int>& nums, int goal)
    {
        int window_start=0, window_end=0, ans=0,count=0;
        if (goal < 0)
            return 0;
        for(window_end=0; window_end<nums.size() ;window_end++)
        {
            count+=nums[window_end];
            while(count>goal)
            {
                count-=nums[window_start];
                window_start++;
            }
            ans+=window_end-window_start+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};