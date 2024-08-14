class Solution {
public:
    
    bool check(int mid,vector<int> &nums,int k){
        
        int cnt=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int idx=upper_bound(nums.begin(),nums.end(),nums[i]+mid)-nums.begin();
            idx--;
            cnt+=(idx-i);
        }
        
        return (cnt>=k);
        
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        // binary search on difference
        int l=-1,r=1e6;
        while(r-l>1){
            int mid=(l+r)>>1;
            if(check(mid,nums,k))
                r=mid;
            else 
                l=mid;
        }
        return r;
    }
};