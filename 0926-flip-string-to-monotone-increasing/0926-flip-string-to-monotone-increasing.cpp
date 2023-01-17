class Solution {
public:
    int minFlipsMonoIncr(string str) {
        int n = str.length();
        vector<vector<int>>dp(n+2, vector<int>(2, -1));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int index=n-1;index>=0;index--){
            for(int prev = 0;prev<2;prev++){
                int res = INT_MAX;
                // not change
                if(prev == 0 || (prev == 1 && str[index] == '1')){
                    res = min(res, dp[index+1][str[index] - '0']);
                }

                // change
                int val = str[index] - '0';

                if(prev == 0 || (prev == 1 && val == 0)){
                    res = min(res, 1 + dp[index+1][1-val]);
                }

                dp[index][prev] = res;
            }
        }

        return dp[0][0];
    }
};