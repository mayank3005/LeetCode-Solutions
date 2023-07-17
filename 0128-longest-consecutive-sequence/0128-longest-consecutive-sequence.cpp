class Solution {
    class DSU{
        public:
        int n;
        vector<int> par, size;
        DSU(int n){
            this->n=n;
            size.resize(n,1);
            for(int i=0;i<n;i++){
                par.push_back(i);
            }
        }
        int findPar(int u){
            if(par[u]==u) return u;
            return par[u]=findPar(par[u]);
        }
        void Union(int u,int v){
            u=findPar(u);v=findPar(v);
            if(size[u]<=size[v]) par[u]=v,size[v]+=size[u];
            else par[v]=u,size[u]+=size[v];
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        DSU dsu(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) continue;
            if(mp.find(nums[i]-1)!=mp.end()){
                dsu.Union(i,mp[nums[i]-1]);
            }
            if(mp.find(nums[i]+1)!=mp.end()){
                dsu.Union(i,mp[nums[i]+1]);
            }
            mp[nums[i]]=i;
        }
        int ans=0;
        // for(auto i:dsu.size) cout<<i<<' ';
        for(int i=0;i<nums.size();i++) ans=max(ans,dsu.size[i]);
        return ans;
    }
};