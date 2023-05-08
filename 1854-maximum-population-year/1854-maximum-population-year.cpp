class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for(auto &i:logs){
            mp[i[0]]++;mp[i[1]]--;
        }
        int curr=0,ans=0,mx=0;
        for(auto &[x,y]:mp){
            curr+=y;
            if(curr>ans){
                mx=x;ans=curr;
            }
        }
        return mx;
    }
};