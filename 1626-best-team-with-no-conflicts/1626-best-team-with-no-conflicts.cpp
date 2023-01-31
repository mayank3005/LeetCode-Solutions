class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = size(ages), idx[1000], dp[1000] = {};
        iota(idx, idx+n, 0);
        sort(idx, idx+n, [&] (int i, int j) {
            return ages[i] < ages[j] || (ages[i] == ages[j] && scores[i] < scores[j]);
        });
        for (int i = 0; i < n; i++) {
            dp[i] = scores[idx[i]];
            for (int j = 0; j < i; j++) {
                if (scores[idx[i]] >= scores[idx[j]])
                    dp[i] = max(dp[i], dp[j] + scores[idx[i]]);
            }
        }
        return *max_element(dp, dp+n);
    }
};