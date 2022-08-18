class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        
        priority_queue<int> pq;
        for(auto &[val,cnt]:mp) pq.push(cnt);
        
        int val=0,sum=0;
        while(!pq.empty() and sum<n/2){
            sum+=pq.top();pq.pop();val++;
        }
        return val;
    }
};