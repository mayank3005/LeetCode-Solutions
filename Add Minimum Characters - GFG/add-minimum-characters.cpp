//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        string temp=str; reverse(temp.begin(),temp.end());
        str.push_back('%'); str+=temp;reverse(str.begin(),str.end());
        
        int n=str.size(); int lps[n]; lps[0]=0;
        int i=0,j=1;
        while(j<n){
            if(str[i]==str[j]){
                lps[j++]=++i;
            }else{
                if(i) i=lps[i-1];
                else lps[j++]=0;
            }
        }
        // cout<<str<<endl;
        return temp.size()-lps[str.size()-1];
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
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends