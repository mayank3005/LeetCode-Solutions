class Solution {
public:
    int minSteps(string s, string t) {
        
        int count=0;
        vector<int> arr(26,0);
        for(auto i:s)
            arr[i-'a']++;
        for(auto i:t)
            arr[i-'a']--;
        for(auto i:arr)
            count+=abs(i);
        return count;  
    }
};