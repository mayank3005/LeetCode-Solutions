class Solution {
public:
    
    int f(vector<int> &heights){
        int n=heights.size();
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i]) st.pop();
            left[i]=(st.empty()?-1:st.top());
            st.push(i);
        }
        
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]) st.pop();
            right[i]=(st.empty()?n:st.top());
            st.push(i);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int m=mat.size(),n=mat[0].size();
        
        int ans=-1;
        
        for(int i=0;i<m;i++){
            vector<int> val(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    if(mat[j][k]=='1') val[k]++;
                    else val[k]=0;
                }
                ans=max(ans,f(val));
            }
        }
        return ans;
    }
};