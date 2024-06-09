class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        ans.push_back(v[0]); int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i][0]<=ans.back()[1]) ans.back()[1]=max(ans.back()[1],v[i][1]);
            else ans.push_back(v[i]);
        }
        return ans;
    }
};