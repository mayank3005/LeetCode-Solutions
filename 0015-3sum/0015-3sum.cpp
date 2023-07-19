class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;){
            int j=i+1,k=n-1; int sum=-nums[i];
            while(j<k){
                int curr=nums[j]+nums[k];
                if(curr==sum) ans.push_back({nums[i],nums[j],nums[k]}),j++,k--;
                else if(curr<sum) j++;
                else k--;
                while(j!=i+1 and j<n and nums[j]==nums[j-1]) j++;
                while(k!=n-1 and k>j and nums[k]==nums[k+1]) k--;
            }
            i++;
            while(i<n and nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};