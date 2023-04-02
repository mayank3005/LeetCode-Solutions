class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size()); 
        vector<pair<int,int>> val;
        for(int i=0;i<spells.size();i++){
            val.push_back({spells[i],i});
        }
        sort(val.begin(),val.end()); sort(potions.begin(),potions.end());
        int m=spells.size(),n=potions.size();
        int i=0,j=n-1;
        while(i<m and j>=0){
            while(j>=0 and val[i].first*1LL*potions[j]>=success) j--;
            ans[val[i].second]=n-1-j;
            i++;
        }
        while(i<m) ans[val[i++].second]=n;
        return ans;
    }
};