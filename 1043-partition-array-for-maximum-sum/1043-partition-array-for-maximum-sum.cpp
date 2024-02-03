class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int dp[n+1]; dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int maxi=INT_MIN,fin=INT_MIN;
            for(int idx=i;idx-i<k and idx<n;idx++){
                maxi=max(maxi,arr[idx]);
                fin=max(fin,maxi*(idx-i+1)+dp[idx+1]);
            }  
            dp[i]=fin;
        }
        return dp[0];
    }
};