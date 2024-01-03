class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0; int ans=0;
        for(auto &s:bank){
            int curr=0;
            for(auto i:s) curr+=(i=='1');
            if(prev and curr) ans+=prev*curr,prev=curr; 
            else if(!prev) prev=curr;
        }
        return ans;
    }
};