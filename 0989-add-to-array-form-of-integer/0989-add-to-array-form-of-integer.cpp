class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int> b;
        while(k){
            b.push_back(k%10);k/=10;
        }
        reverse(a.begin(),a.end());
        if(a.size()<b.size()){
            vector<int> temp=a;
            a=b;b=temp;
        }
        int m=a.size(),n=b.size();
        int i=0,rem=0;
        while(i<n){
            int val=a[i]+b[i]+rem;
            a[i]=val%10;rem=val/10;
            i++;
        }
        while(i<m){
            int val=a[i]+rem;
            a[i]=val%10;rem=val/10;i++;
        }
        if(rem) a.push_back(rem);
        
        reverse(a.begin(),a.end());return a;
        
    }
};