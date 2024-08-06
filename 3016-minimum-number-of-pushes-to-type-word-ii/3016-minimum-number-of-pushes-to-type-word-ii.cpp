class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        for(auto i:word) mp[i]++;
        int ans=0; int curr=0;
        priority_queue<int> pq;
for (auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push(it->second);
        }
        while(!pq.empty()){
            int t=pq.top();pq.pop();
            ans+=(curr/8 + 1)*t; curr++;
        }
        return ans;
    }
};