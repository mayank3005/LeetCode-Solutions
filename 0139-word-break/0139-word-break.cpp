class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> mp(wordDict.begin(),wordDict.end());
        int n=s.length(); int dp[n+1]; dp[n]=1;
        for(int i=n-1;i>=0;i--){
            string temp=""; dp[i]=0;
            for(int j=i;j<n;j++){
                temp.push_back(s[j]);
                if(mp.find(temp)!=mp.end()) dp[i]|=dp[j+1];
            }
        }
        return dp[0];
    }
};