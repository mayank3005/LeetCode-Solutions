//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{

  public:

  int LargestRectinHistogram(vector<int>& hist){

      stack<int> st;
    
      int top;
    
      int ans=0;
    
      hist.push_back(0);   
    
      for(int i=0;i<=hist.size();i++){
    
          while(!st.empty() && hist[st.top()]>hist[i]){
        
              top=hist[st.top()];
        
              st.pop();
        
              int ran=st.empty()?-1:st.top();
        
              ans=max((i-ran-1)*top,ans);
              
          }
    
        st.push(i);
          
      }
    
       return ans;
      
  }


   int maxArea(int M[MAX][MAX], int n, int m) {

        int maxarea=0;
        
            vector<int> histi(m+1,0);
        
          for(int i=0;i<n;i++){
        
              for(int j=0;j<m;j++){
        
           histi[j]=M[i][j]?histi[j]+1:0;
        
              }
        
              maxarea=max(maxarea,LargestRectinHistogram(histi));
        }  
          return maxarea;
    }

};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends