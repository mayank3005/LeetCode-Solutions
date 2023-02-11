class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<vector<int> > red(n), blue(n);
        for(int i=0;i<r.size();i++) {
            red[r[i][0]].push_back(r[i][1]);
        }
        for(int i=0;i<b.size();i++) {
            blue[b[i][0]].push_back(b[i][1]);
        }
        queue<pair<int, char> > q;
        q.push({0,'R'});
        q.push({0,'B'});
        vector<pair<int,int> > dis(n,{INT_MAX, INT_MAX});
        dis[0]={0,0};
        while(!q.empty()) {
            int i=q.front().first;
            char c = q.front().second;
            q.pop();
            if(c=='R') {
                for(auto x: blue[i]) {
                    if(dis[x].second>dis[i].first+1) {
                        dis[x].second=dis[i].first+1;
                        q.push({x,'B'});
                    }
                }
            }
            else {
                for(auto x: red[i]) {
                    if(dis[x].first>dis[i].second+1) {
                        dis[x].first=dis[i].second+1;
                        q.push({x,'R'});
                    }
                }
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            if(dis[i].first==INT_MAX && dis[i].second==INT_MAX) {
                ans[i]=-1;
            }
            else {
                ans[i]=min(dis[i].first, dis[i].second);
            }
        }
        return ans;
    }
};