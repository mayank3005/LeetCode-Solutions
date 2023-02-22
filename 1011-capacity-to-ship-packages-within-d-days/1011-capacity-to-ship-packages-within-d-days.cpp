class Solution {
public:
    int shipWithinDays(vector<int>& a, int b) {
        int l=0,r=1e9;
        while(r-l>1){
            int mid=(l+r)>>1;
            bool check=true;
            int days=1,tot=0;
            for(int i=0;i<a.size();i++){
                if(a[i]>mid) check=false;
                tot+=a[i];
                if(tot>mid) tot=a[i],days++;
            }
            if(days>b) check=false;
            if(check) r=mid;
            else l=mid;
        }
        return r;        
    }
};