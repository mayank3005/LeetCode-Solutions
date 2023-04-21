class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        vector<vector<int>> suff(n+1,vector<int>(10,-1));
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<10;j++){
                suff[i][j]=suff[i+1][j];
            }
            suff[i][num[i+1]-'0']=i+1;
        }
        int i=0,j; string ans="";
        while(i<n){
            for(int s=0;s<num[i]-'0';s++){
                j=suff[i][s];
                if(j==-1) continue;
                if(j-i<=k) {k-=(j-i);i=j;break;}
            }
            // cout<<i<<" "<<k<<endl; 
            ans.push_back(num[i++]);
        }
        while(k-- >0 and ans.size()) ans.pop_back();
        reverse(ans.begin(),ans.end());
        while(ans.size()>1 and ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans.size()?ans:"0";
    }
};