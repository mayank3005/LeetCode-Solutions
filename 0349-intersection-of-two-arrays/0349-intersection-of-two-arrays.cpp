class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> st(nums1.begin(),nums1.end());
        
        vector<int> ans;
        for(auto i:nums2){
            if(st.find(i)!=st.end()){
                ans.push_back(i);
                st.erase(i);
            }
        }
        return ans;
    }
};