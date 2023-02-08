class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();

        int jumps=0,farthest=0,current=0;
        if(n>1 and !a[0]) return -1;

        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+a[i]);
            if(current==i){
                current=farthest;
                jumps++;
            }        
        }

        if(farthest<n-1) return -1;
        return jumps;        
    }
};