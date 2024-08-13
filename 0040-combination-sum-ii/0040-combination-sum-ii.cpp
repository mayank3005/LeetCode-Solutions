class Solution {
public:
    
    void solve(vector<int> &c,int t,int ind,vector<int> &temp,vector<vector<int>> &ans){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<c.size();i++){
            if(i!=ind and c[i]==c[i-1]) continue;
            if(c[i]>t) break;
            temp.push_back(c[i]);
            solve(c,t-c[i],i+1,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates,target,0,temp,ans);
        return ans;
    }
};