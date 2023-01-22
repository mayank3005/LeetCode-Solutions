class Solution {
public:
    
    bool ispallin(string &s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    void solve(string s,int idx,vector<string> &path,vector<vector<string>> &ans){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(ispallin(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,0,path,ans);
        return ans;
    }
};