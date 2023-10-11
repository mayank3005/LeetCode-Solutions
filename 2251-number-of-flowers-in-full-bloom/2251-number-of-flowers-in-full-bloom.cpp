class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        map<int,int> mp;
        for(auto &i:f) mp[i[0]]++,mp[i[1]+1]--;
        int pref=0;
        for(auto i:p){
            if(mp.count(i)==0) mp[i]=0;
        }
        for(auto &[x,y]:mp){
            mp[x]+=pref;
            pref=mp[x];
        }
        vector<int> ans;
        for(auto i:p) ans.push_back(mp[i]);
        return ans;
        
    }
};