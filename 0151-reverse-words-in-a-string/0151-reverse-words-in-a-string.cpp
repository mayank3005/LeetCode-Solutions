class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0,j=0,cnt=0;
        while(i<s.size()){
            if(j==s.size() or s[j]==' '){
                cnt++;
                int x=i,y=j-1;
                while(x<y){
                    swap(s[x++],s[y--]);
                }
                i=j+1;j++;
            }
            j++;
        }
        string ans="";
        for(int i=0;i<s.size();){
            if(s[i]!=' '){
                while(i<s.size() and s[i]!=' '){
                    ans.push_back(s[i++]);
                }
                ans.push_back(' ');
            }
            i++;
        }
        i=ans.size()-1;
        while(ans[i]==' ') ans.pop_back();
        return ans;
    }
};