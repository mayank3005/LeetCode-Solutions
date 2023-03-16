//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
string smallestWindow (string s, string p)

    {

        if(s.size()<p.size()) return "-1";

        int i=0,j=0;

        unordered_map<char,int>mp1;

        unordered_map<char,int>mp2;

        for(int i=0;i<p.size();i++) mp1[p[i]]++;

        int cnt1=mp1.size(),cnt2=0; 

        int len=INT_MAX,st=-1,en=-1;

        while(j<s.size()){

            mp2[s[j]]++;

            if(mp2[s[j]]==mp1[s[j]]) cnt2++;

            if(cnt1==cnt2)

            {  
                while(mp2[s[i]]>mp1[s[i]])

                { 
                      mp2[s[i]]--;  i++;
                }

                if(len>j-i+1)

                {
                    len=j-i+1; st=i; en=j;
                }

            }

            j++;

        }

        if(st==-1) return "-1";

        return s.substr(st,en-st+1);

    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends