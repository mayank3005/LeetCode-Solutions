class Solution {
public:
    const int mod=1e9+7;
    int concatenatedBinary(int n) {
        
        long long ans=0;
        
        for(int i=1;i<=n;i++){
            int shift=1+(int)(log2(i));
            ans=((ans<<shift)%mod+i)%mod;
        }
        return ans;
    }
};