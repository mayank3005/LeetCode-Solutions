class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> mp;
        for(auto s:words){
            for(auto i:s) mp[i]++;
        }
        int n=words.size();
        for(auto it:mp){
            if(it.second%n) return false;
        }
        return true;
    }
};