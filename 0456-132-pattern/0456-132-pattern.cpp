class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st; int n=nums.size();
        int mn[n]; mn[0]=nums[0];
        for(int i=1;i<n;i++){
            mn[i]=min(mn[i-1],nums[i]);
        }
        // traversing for s2
        for(int i=n-1;i>=1;i--){
            // s2>s1
            if(nums[i]>mn[i]){
                // making s3>s1
                while(!st.empty() and st.top()<=mn[i]) st.pop();
                // s2>s3
                if(!st.empty() and st.top()<nums[i]) return true;
                st.push(nums[i]);
            }
        }
        return false;
    }
};