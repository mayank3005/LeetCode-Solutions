class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    string s="";
    int n=str1.size();
    int m=str2.size();
    int k=__gcd(n,m);
    for(int i=0;i<m;i++){
        if(str1[i%k]!=str2[i]){
        return  "";
        }
    }
    for(int i=0;i<n;i++){
        if(str2[i%k]!=str1[i]){
        return  "";
        }
    }
    return str1.substr(0,k);
    }
};