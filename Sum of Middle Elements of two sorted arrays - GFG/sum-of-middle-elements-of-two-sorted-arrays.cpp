//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            int i=0,j=0;
            int prev=n-1,after=n;
            int prevEle,afterEle;
            while(i<n and j<n){
                int elem;
                if(ar1[i]<ar2[j]){
                    elem=ar1[i++];
                }else{
                    elem=ar2[j++];
                }
                if(i+j-1==prev) prevEle=elem;
                if(i+j-1==after) afterEle=elem;
                // cout<<i+j-1<<' '<<elem<<endl;
            }
            while(i<n){
                int elem=ar1[i++];
                if(i+j-1==prev) prevEle=elem;
                if(i+j-1==after) afterEle=elem;
                // cout<<i+j-1<<' '<<elem<<endl;
            }
            while(j<n){
                int elem=ar2[j++];
                if(i+j-1==prev) prevEle=elem;
                if(i+j-1==after) afterEle=elem;
                // cout<<i+j-1<<' '<<elem<<endl;
            }
            return prevEle+afterEle;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends