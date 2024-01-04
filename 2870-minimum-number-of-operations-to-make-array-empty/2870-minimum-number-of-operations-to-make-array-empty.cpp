class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums) mp[i]++;
        int ans=0;
        for(auto &[x,y]:mp){
            if(y<2) return -1;
            ans+=(y/6)*2;
            y%=6;
            if(y==0) continue;
            if(y<=3) ans++; 
            else ans+=2;
        }
        return ans;
    }
};