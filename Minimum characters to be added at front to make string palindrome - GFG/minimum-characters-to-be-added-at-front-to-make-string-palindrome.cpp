//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> computeLPS(string &s) {
    	int n = s.length();
    	vector<int> lps(n);
    	lps[0] = 0;
    
    	int i = 1, len = 0;
    	while (i < n) {
    		if (s[len] == s[i]) {
    			lps[i++] = ++len;
    		} else {
    			if (len) len = lps[len - 1];
    			else lps[i++] = 0;
    		}
    	}
    	return lps;
    }

    int minChar(string str){
        //Write your code here
        int n=str.length();
        string revStr=str;
        reverse(revStr.begin(),revStr.end());str+=revStr;
        vector<int> lps=computeLPS(str);
        return n-lps.back();
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends