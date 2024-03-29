class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,r=1e14;
        while(l+1<r){
            long long mid=(l+r)>>1;
            long long trips=0;
            for(auto i:time) trips+=mid/i;
            if(trips>=totalTrips) r=mid;
            else l=mid;
        }
        return r;
    }
};