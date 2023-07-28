class Solution {
public:
    bool f(int a,int b,int c,string &s1,string &s2,string &s3){
        if(c<0) return true;
        if(a>=0 and b>=0 and s1[a]==s2[b] and s2[b]==s3[c]) return f(a-1,b,c-1,s1,s2,s3) or f(a,b-1,c-1,s1,s2,s3);
        if(a>=0 and s1[a]==s3[c]) return f(a-1,b,c-1,s1,s2,s3);
        if(b>=0 and s2[b]==s3[c]) return f(a,b-1,c-1,s1,s2,s3);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        return f(s1.length()-1,s2.length()-1,s3.length()-1,s1,s2,s3);
    }
};