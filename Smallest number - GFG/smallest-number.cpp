//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
string smallestNumber(int S, int D){
        // code here 
        if(S>9*D) return "-1";
        string ans = "";
        for(int i=0; i<D; i++){
            ans+="0";
        }
        int ind = D-1;
        int sumL = S-1;
        while(sumL>0 && ind>=0){
            if(sumL>=9){
                sumL-=9;
                ans[ind] = '9';
                ind--;
            }
            else{
                break;
            }
        }
        
        if(ind>0) ans[ind]='0'+sumL,ans[0]='1';
        else if(ind==0) ans[ind]='0'+(sumL+1);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends