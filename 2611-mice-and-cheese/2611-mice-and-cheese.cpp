class Solution {
public:
    int miceAndCheese(vector<int> A, vector<int>& B, int k) {
        int n = A.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            A[i] -= B[i];
            res += B[i];
        }
        nth_element(A.begin(), A.begin() + k, A.end(), greater<int>());
        return accumulate(A.begin(), A.begin() + k, res);
    }
};