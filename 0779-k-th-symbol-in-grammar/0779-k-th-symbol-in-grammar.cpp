class Solution {
public:
    int kthGrammar(int n, int k) {
        int cnt=0; k--;
        while(n>1){
            if(k%2) cnt++,cnt%=2;
            k/=2;
            n--;
        }
        return cnt;
    }
};