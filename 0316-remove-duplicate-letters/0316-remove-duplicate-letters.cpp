class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> vis(26,false);
        vector<int> last(26,-1);
        string ans="";
        
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a']) continue;
            while(!ans.empty() and ans.back()>s[i] and last[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]-'a']=true;
        }
        
        return ans;
    }
};