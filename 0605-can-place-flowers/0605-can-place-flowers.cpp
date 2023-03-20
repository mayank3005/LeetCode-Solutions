class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);flowerbed.push_back(0);
        int cnt0=0;int sz=flowerbed.size(),ans=0;
        for(int i=0;i<sz;i++){
            if(!flowerbed[i]) cnt0++;
            else{
                cnt0--;
                if(cnt0>0) ans+=cnt0/2;
                cnt0=0;
            }
        }
        cnt0--;
        if(cnt0>=2) ans+=cnt0/2;
        return ans>=n;
    }
};