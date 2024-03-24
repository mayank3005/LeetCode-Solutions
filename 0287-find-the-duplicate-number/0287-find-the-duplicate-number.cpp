class Solution {
public:
    int findDuplicate(vector<int>& a) {
            int n=a.size();
    
    if(n==1) return -1;
    
    int slow=n;
    int fast=n;
    
    do{
        fast=a[a[fast-1]-1];
        slow=a[slow-1];
    }while(slow!=fast);
    
    slow=n;
    do{
        slow=a[slow-1];fast=a[fast-1];
    }while(slow!=fast);
    return slow;
    }
};