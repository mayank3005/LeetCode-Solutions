class Solution {
public:
    int peakIndexInMountainArray(vector<int>& n) {
        int l = 1, r = n.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (n[m] < n[m + 1])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};