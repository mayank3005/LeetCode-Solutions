class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mp;
        
        for(auto str:words){
            mp[str]++;
        }
        
        int len=0;int flag=0;
        for(auto str:words){
            string rev=str;
            if(mp[str]<=0) continue;
            reverse(rev.begin(),rev.end());
            if(mp[rev]>0 and str[0]!=str[1]) len+=4,mp[rev]--,mp[str]--;
            else if(str[0]==str[1] and mp[rev]>1) len+=4,mp[rev]--,mp[str]--;
            else if(str[0]==str[1]) flag=2,mp[str]--;
        }
        
        return len+flag;
        
    }
};