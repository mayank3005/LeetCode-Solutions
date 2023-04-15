class Solution {
public:
    bool check(vector<int> &nums,int x,int p){
        int ans=0; int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=x) ans++,i++;
        }
        return (ans>=p);
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int l=-1,r=nums.back()-nums[0]; 
        while(l+1<r){
            int mid=(l+r)>>1;
            if(check(nums,mid,p)) r=mid;
            else l=mid;
        }
        return r;
    }
};