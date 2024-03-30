class Solution {
public:
    
    int atmost(vector<int> &v,int k){
        
        int i=0,j=0;
        unordered_map<int,int> mp;
        
        int ans=0;
        while(j<v.size()){
            mp[v[j]]++;
            while(mp.size()>k){
                mp[v[i]]--;
                if(mp[v[i]]==0) mp.erase(v[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};