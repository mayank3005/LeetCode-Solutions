class Solution {
public:
    int removeElement(vector<int>& A, int elem) {
        int begin=0; int n=A.size();
        for(int i=0;i<n;i++) if(A[i]!=elem) A[begin++]=A[i];
        return begin;
    }
};