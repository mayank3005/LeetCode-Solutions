class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length()) swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;int m=a.length();int n=b.length();
        int rem=0;string ans="";
        while(i<m){
            int x=a[i]-'0',y=0;
            if(i<n) y=b[i]-'0';
            int val=x+y+rem;
            ans.push_back('0'+val%2);
            rem=val/2;i++;
        }
        if(rem) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};