class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end()); reverse(s.begin(),s.end());
        if(s.back()=='1') return s;
        int i=s.length()-1;
        while(i>=0 and s[i]=='0') i--;
        s[i]='0';s[s.length()-1]='1';
        return s;
    }
};