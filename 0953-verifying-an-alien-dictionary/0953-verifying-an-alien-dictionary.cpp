class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for(int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        int size = words.size();
        for(int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            if(s1 == s2) continue;
            if(s1.length() > s2.length()) {
                int len = s2.length();
                if(s2 == s1.substr(0, len)) return false;
            }
            int index = 0;
            while(index != s1.length() || index != s2.length()) {
                if(mp[s1[index]] == mp[s2[index]]) {
                    index++;
                    continue;
                }
                else if(mp[s1[index]] < mp[s2[index]]) {
                    break;
                }
                else return false;
            }
        }
        return true;
    }
};