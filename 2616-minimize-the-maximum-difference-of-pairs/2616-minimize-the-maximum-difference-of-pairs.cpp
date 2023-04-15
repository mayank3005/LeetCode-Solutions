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
        if(n==1 or p==0) return 0;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0]; int ans=r;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(nums,mid,p)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};