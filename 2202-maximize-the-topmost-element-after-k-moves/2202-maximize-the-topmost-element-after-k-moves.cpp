class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size(); if(k==0) return nums[0];
        if(n==1 and k&1) return -1; 
        int mx=-1;
        for(int i=0;i<n and i<k-1;i++) mx=max(mx,nums[i]);
        k=min(k,n+1);
        int last; 
        if(k==n+1) last=nums.back();
        else if(k==n) last=-1;
        else last=nums[k];
        return max(mx,last);
    }
};