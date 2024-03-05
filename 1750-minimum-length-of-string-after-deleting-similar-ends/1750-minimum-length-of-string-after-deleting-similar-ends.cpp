class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) break; char ch=s[i];
            while(i<=j and s[i]==ch) i++;
            while(j>=i and s[j]==ch) j--;
        }
        return j-i+1;
    }
};