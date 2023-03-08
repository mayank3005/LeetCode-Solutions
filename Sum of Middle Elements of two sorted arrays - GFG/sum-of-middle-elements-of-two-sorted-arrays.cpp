//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int nums1[], int nums2[], int n) {
            // code here 
        int n1=n,n2=n;
        int l=0,r=n;
        while(l<=r){
            int cut1=(l+r)>>1;
            int cut2=(n1+n2)/2-cut1;
            
            int l1,l2,r1,r2;
            l1=l2=INT_MIN,r1=r2=INT_MAX;
            if(cut1) l1=nums1[cut1-1];
            if(cut2) l2=nums2[cut2-1];
            if(cut1!=n1) r1=nums1[cut1];
            if(cut2!=n2) r2=nums2[cut2]; 
            
            if(l1<=r2 and l2<=r1){
                return max(l1,l2)+min(r2,r1);
            }
            
            if(l1>r2) r=cut1-1;
            else l=cut1+1;
            
        }
        return 0;
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