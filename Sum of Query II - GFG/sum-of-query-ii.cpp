//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int segmentTree(int arr[], vector<int> &sTree, int sInd, int l, int h){
        if(l==h){
            sTree[sInd] = arr[l];
            return arr[l];
        }
        int mid = l + (h-l)/2;
        sTree[sInd] = segmentTree(arr,sTree,2*sInd + 1, l,mid) + 
                        segmentTree(arr,sTree,2*sInd + 2, mid+1,h);
        return sTree[sInd];
    }
    int sumR(vector<int> &sTree, int si, int sl, int sr, int l,int r){
        if(l<=sl && r>=sr){
            return sTree[si];
        }
        if(sl>r || sr<l) return 0;
        int mid = sl + (sr-sl)/2;
        return sumR(sTree,2*si + 1, sl,mid,l,r) + sumR(sTree, 2*si + 2, mid+1,sr,l,r);
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        int ht = (int)(ceil(log2(n)));
        int sz = 2*(int)pow(2,ht) - 1;
        vector<int> sTree(sz);
        vector<int> res;
        segmentTree(arr,sTree,0,0,n-1);
        for(int i=0; i<2*q; i+=2){
            int x = sumR(sTree,0,0,n-1,queries[i]-1,queries[i+1]-1);
            res.push_back(x);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends