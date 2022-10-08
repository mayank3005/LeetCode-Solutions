class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int ans=1e8;
        
        for(int k=0;k<n;k++){
            int i=k+1,j=n-1;
            while(i<j){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>target) j--;
                else i++;
                if(abs(sum-target)<abs(ans-target)) ans=sum;
            }
        }
        return ans;
    }
};