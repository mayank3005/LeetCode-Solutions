class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minv=1e9;int ans=0;
        for(auto i:prices){
            ans=max(ans,i-minv);
            minv=min(minv,i);
        }
        return ans;
    }
};