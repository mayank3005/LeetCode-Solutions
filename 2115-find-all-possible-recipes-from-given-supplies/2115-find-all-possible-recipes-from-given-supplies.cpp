class Solution {
public:
    
    void dfs(string &src,unordered_map<string,vector<string>> & adj,unordered_set<string> &vis,vector<string> &ans){
        
        vis.insert(src);
        for(auto dest:adj[src]){
            if(vis.count(dest)) continue;
            dfs(dest,adj,vis,ans);
        }
        
        ans.push_back(src);
        
    }
    
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        
        vector<string> ans;
        
        unordered_map<string,vector<string>> adj;
        int n=rec.size();
        for(int i=0;i<n;i++){
            for(auto &str:ing[i]) adj[rec[i]].push_back(str);
        }
        
        unordered_set<string> vis;
        
        for(int i=0;i<n;i++){
            if(!vis.count(rec[i])) 
                dfs(rec[i],adj,vis,ans);
        }
        unordered_set<string> supp_pres(sup.begin(),sup.end());
        unordered_set<string> rec_pres(rec.begin(),rec.end());
        
        vector<string> res;
        
        for(auto &str:ans){
            if(supp_pres.count(str)){
                if(rec_pres.count(str)){
                    res.push_back(str);
                }
            }else{
                if(rec_pres.count(str)){
                    bool check=true;
                    for(auto &s:adj[str]){
                        if(!supp_pres.count(s)) check=false;
                    }
                    if(check) res.push_back(str),supp_pres.insert(str);
                }
            }            
        }
        return res;
    }
};