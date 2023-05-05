class Solution {
public:
    bool isVowel(char ch){
        return ((ch=='a')or(ch=='e')or(ch=='i')or(ch=='o')or(ch=='u'));
    }
    int maxVowels(string s, int k) {
        int i=0,j=0,cnt=0,ans=0;
        while(j<k){
            if(isVowel(s[j])) cnt++;
            j++;
        }
        ans=max(ans,cnt);
        while(j<s.length()){
            if(isVowel(s[j])) cnt++;
            if(isVowel(s[i])) cnt--;
            ans=max(ans,cnt); i++,j++;
        }
        return ans;
    }
};