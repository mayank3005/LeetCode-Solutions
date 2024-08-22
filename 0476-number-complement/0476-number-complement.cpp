class Solution {
public:
    int findComplement(int n) {
        return (unsigned)~0 >> __builtin_clz(n) ^ n;
    }
};