class Solution {
public:
    vector<vector<int>> ans;
    void f(int idx,int sum,int sz,int k,int n,vector<int> &res){
        if(sz>k or sum>n) return;
        if(sz==k and sum==n) {ans.push_back(res);return;} 
        for(int i=idx;i<=9;i++){
            res.push_back(i);
            f(i+1,sum+i,sz+1,k,n,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        f(1,0,0,k,n,res);
        return ans;
    }
};