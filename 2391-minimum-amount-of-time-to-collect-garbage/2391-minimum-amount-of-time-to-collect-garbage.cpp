class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& tr) {
        
        int n=g.size();
        vector<vector<int>> gg(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            for(auto &ch:g[i]){
                if(ch=='M') gg[i][0]++;
                else if(ch=='G') gg[i][1]++;
                else gg[i][2]++;
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<gg[i][0]<<" "<<gg[i][1]<<" "<<gg[i][2]<<endl;
        // }
        
        long long ans=0;
        for(int i=0;i<3;i++){
            int j=n-1;
            while(j>=0 and gg[j][i]==0) j--;
            if(j==-1) continue;
            int k=0;
            while(k<=j){
                if(k) ans+=tr[k-1];
                ans+=gg[k][i];
                k++;
            }
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};