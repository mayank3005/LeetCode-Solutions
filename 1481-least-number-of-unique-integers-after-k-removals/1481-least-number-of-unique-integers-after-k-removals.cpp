#define pii pair<int,int> 

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto i:arr) mp[i]++;
        vector<pii> v; 
        for(auto &[x,y]:mp) v.push_back({x,y});
        sort(v.begin(),v.end(),[](pii &a,pii &b){
            return a.second<b.second;
        });
        int ans=0;
        for(auto &[_,x]:v){
            if(k>=x) k-=x,ans++;
            else break;
        }
        return mp.size()-ans;
    }
};