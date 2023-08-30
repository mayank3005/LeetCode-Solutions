class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0,n=0;
        for(auto i:customers){
            if(i=='Y') y++;
        }
        int ans=y,res=0; int cnt=1;
        for(auto i:customers){
            if(i=='N') n++;
            else y--;
            if(ans>y+n) res=cnt,ans=y+n;
            cnt++;
        }
        return res;
    }
};