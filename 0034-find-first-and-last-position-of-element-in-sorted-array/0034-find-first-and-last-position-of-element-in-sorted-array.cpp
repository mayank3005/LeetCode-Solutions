class Solution {
public:
    
    int ub(vector<int> &nums,int x){
        
        int n=nums.size();
//         l --> always <= x
        int l=0,r=n;
        
        while(r-l>1){
            int mid=(l+r)/2;
            if(nums[mid]>x) r=mid;
            else l=mid;
        }
        
        return nums[l]==x?l:-1;
    }
    
    int lb(vector<int> &nums,int x){
        
        int n=nums.size();
//         r --> always >= x
        int l=-1,r=n-1;
        
        while(r-l>1){
            int mid=(l+r)/2;
            if(nums[mid]>=x) r=mid;
            else l=mid;
        }
        
        return nums[r]==x?r:-1;
    }   
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size()==0) return {-1,-1};
        
        int n=nums.size();
        
        vector<int> ans(2,-1);
        ans[0]=lb(nums,target);
        ans[1]=ub(nums,target);
        
        return ans;
    }
};