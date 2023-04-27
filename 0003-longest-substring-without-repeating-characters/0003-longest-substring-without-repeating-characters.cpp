class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]={0}; int c=0;
        int i=0,j=0; int n=s.length(); int ans=0;
        while(j<n){
            int idx=s[j]-'\0';
            freq[idx]++; if(freq[idx]==1) c++;
            while(freq[idx]>1){
                if(freq[s[i]-'\0']==1) c--;
                freq[s[i++]-'\0']--;
            }
            ans=max(ans,c); ++j;
        }
        return ans;
    }
};