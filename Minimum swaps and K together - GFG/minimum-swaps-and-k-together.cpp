//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
    int snowBallSize = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Calculating the size of window required
        if (arr[i] <= k) {
            snowBallSize++;
        }
    }
 
    int swap = 0, ans_swaps = INT_MAX;
 
    for (int i = 0; i < snowBallSize; i++) {
        if (arr[i] > k)
            swap++;
    }
 
    ans_swaps = min(ans_swaps, swap);
 
    for (int i = snowBallSize; i < n; i++) {
 
        // Checking in every window no. of swaps required
        // and storing its minimum
        if (arr[i - snowBallSize] <= k && arr[i] > k)
            swap++;
        else if (arr[i - snowBallSize] > k && arr[i] <= k)
            swap--;
        ans_swaps = min(ans_swaps, swap);
    }
    return ans_swaps;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends