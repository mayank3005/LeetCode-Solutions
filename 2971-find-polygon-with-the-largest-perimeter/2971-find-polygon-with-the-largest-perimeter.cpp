class Solution {
public:
    long long largestPerimeter(vector<int>& v) {
        sort(v.begin(),v.end());
        long long sum=0; long long ans=-1; int n=v.size();
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(2LL*v[i]<sum and i>=2) ans=sum;
        }
        return ans;
    }
};