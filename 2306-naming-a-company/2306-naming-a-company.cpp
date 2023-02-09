class Solution {
    int count(unordered_map<string, int> &a, unordered_map<string, int> &b) {
        int common = 0;
        for (auto& s : a) {
            if (b.find(s.first) != b.end())
                common++;
        }
        return (a.size() - common) * (b.size() - common);
    }
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_map<string, int>> mp;
        for(auto &idea : ideas) {
            string curr = idea.substr(1, idea.size()-1);
            mp[idea[0]][curr] += 1;
        }
        long long ans = 0;
        for (auto i = mp.begin(); i != mp.end(); i++) {
            for (auto j = i; j != mp.end(); j++) {
                if(i->first == j->first)
                    continue;
                ans += count(i->second, j->second);
            }
        }
        return ans * 2;
    }
};