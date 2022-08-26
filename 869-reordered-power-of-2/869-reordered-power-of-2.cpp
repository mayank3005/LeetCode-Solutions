class Solution {
public:
    vector<int> countdig(int N){
        vector<int>digitsInN(10);
        while(N)
            digitsInN[N % 10]++, N /= 10;
        return digitsInN;
    }
    bool reorderedPowerOf2(int N) {
        vector<int> digitsInN = countdig(N); 
        for(int i = 0, powOf2 = 1; i < 30; i++, powOf2 <<= 1)
            if(digitsInN == countdig(powOf2)) return true;  
        return false;
    }
};