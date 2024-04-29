class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int XOR=0; int ans=0;
        for(auto i:nums) XOR^=i;
        for(int i=0;i<30;i++){
            int bit1=(k>>i)&1; int bit2=(XOR>>i)&1;
            ans+=(bit1^bit2);
        }
        return ans;
    }
};