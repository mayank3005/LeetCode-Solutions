class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=0,r=*max_element(piles.begin(),piles.end());
        
        while(r-l>1){
            int mid=(l+r)>>1;
            
            long timeTaken=0;
            // mid --> bananas that can be eaten per hour
            for(auto i:piles){
                timeTaken+=ceil(1.0*i/mid);
            }
            if(timeTaken<=h) r=mid;
            else l=mid;
        }
        
        return r;
        
    }
};