class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n),right(n);
        stack<pair<int,int>> st;
        st.push({arr[0],1});
        left[0]=1;
        for(int i=1;i<n;i++){
            int cnt=0;
            while(!st.empty() and st.top().first>=arr[i]) 
                cnt+=st.top().second,st.pop();
            // if(!cnt) cnt=1;
            st.push({arr[i],1+cnt});
            left[i]=1+cnt;
        }
        while(!st.empty()) st.pop();
        st.push({arr[n-1],1});
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!st.empty() and st.top().first>arr[i])
                cnt+=st.top().second,st.pop();
            // if(!cnt) cnt=1;
            st.push({arr[i],1+cnt});
            right[i]=1+cnt;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(arr[i]*1LL*left[i]%mod*right[i]%mod))%mod;
        }
        return ans;
    }
};