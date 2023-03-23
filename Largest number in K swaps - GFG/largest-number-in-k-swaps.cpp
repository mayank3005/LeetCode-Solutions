//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void f(string &str,string &ans,int k,int i){
        int n=str.size();
        if(i==str.size() or k==0) {
            ans=max(ans,str);return;
        }
        
        char mx=str[i];
        for(int j=i+1;j<n;j++) mx=max(mx,str[j]);
        
        if(mx!=str[i])k--;
        
        for(int j=i;j<n;j++){
            if(str[j]==mx){
                swap(str[i],str[j]);
                
                f(str,ans,k,i+1);
                swap(str[i],str[j]);
            }
        }
        
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
        string ans=str;
        f(str,ans,k,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends