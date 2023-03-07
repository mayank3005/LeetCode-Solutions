class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size()==1){
            return totalTrips*1LL*time[0];
        }
        long long l=0,r=1e13;
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