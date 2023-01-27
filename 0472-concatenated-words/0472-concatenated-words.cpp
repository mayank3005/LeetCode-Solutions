class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        if(words.size()<2)
            return {};
        unordered_set<string>st(words.begin(),words.end());
        function<bool(string& word,int cur,int cnt)> dfs = [&](string& word,int cur,int cnt)
        {
            if(cur >= word.size())
                return cnt>=2;
            for(int i = cur;i<word.size();i=i+1)
            {
                string t = word.substr(cur,i-cur+1);
                if(st.count(t)&&dfs(word,i+1,cnt+1))
                    return true;
            }
            return false;
        };
        vector<string>ans;
        for(auto & e:words)
        {
            if(words.empty())
                continue;
            if(dfs(e,0,0))
                ans.push_back(e);
        }
        return ans;
    }
};
