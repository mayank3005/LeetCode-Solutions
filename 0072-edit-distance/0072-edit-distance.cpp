class Solution {
public:
    int minDistance(string s, string t) {
        int m=s.size(),n=t.size();
        vector<int> prev(n+1),curr(n+1);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!i) curr[j]=j;
                else if(!j) curr[j]=i;
                else{
                    if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                    else curr[j]=1+min({prev[j],prev[j-1],curr[j-1]});
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};