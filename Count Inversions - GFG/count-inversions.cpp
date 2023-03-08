//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(int st, int mid, int endd, long long v[]) {
    	vector<long long> temp(endd - st + 1);
    	int i = st, j = mid + 1; int k = 0;
    	long long ans=0;
    	while (i <= mid and j <= endd) {
    		if (v[i] <= v[j]) temp[k++] = v[i++];
    		else {
    		    ans+=(mid-i+1);
    		    temp[k++] = v[j++];
    		}
    	}
    	while (i <= mid) temp[k++] = v[i++];
    	while (j <= endd) temp[k++] = v[j++];
    	for (int i = st; i <= endd; i++) {
    		v[i] = temp[i - st];
    	}
    	return ans;
    }
    
    long long merge_sort(int i, int j, long long v[]) {
        long long ans=0;
    	if (i >= j) return ans;
    	int mid = (i + j) >> 1;
    	ans+=merge_sort(i, mid, v);
    	ans+=merge_sort(mid + 1, j, v);
    	ans+=merge(i, mid, j, v);
    	return ans;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return merge_sort(0,N-1,arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends