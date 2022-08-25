class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<int,int> mp;
        for(auto i:r) mp[i]++;
        for(auto i:m) mp[i]--;
        for(auto &[x,y]:mp) if(y>0) return 0;
        return 1;
    }
};