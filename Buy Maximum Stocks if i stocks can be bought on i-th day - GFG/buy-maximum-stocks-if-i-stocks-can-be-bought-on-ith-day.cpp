//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second<b.second;
    }
    
    int buyMaximumProducts(int n, int k, int price[]){
        int noOfStocks=0;
        // day, price
        vector<pair<int, int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(i+1, price[i]));
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0;i<n;i++)
        {
            if(v[i].first*v[i].second > k)
            {
                noOfStocks+=k/v[i].second;
                k-=((k/v[i].second)*v[i].second);
            }
            else
            {
                noOfStocks+=v[i].first;
                k-=(v[i].first*v[i].second);
            }
        }
        
        return noOfStocks;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends