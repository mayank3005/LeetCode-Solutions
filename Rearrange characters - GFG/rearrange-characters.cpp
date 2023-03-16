//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
string rearrangeString(string str)
    {
        if (str.size()==1)
        return str;
        
        string ans = " ";
        
        priority_queue <pair<int,char>> pq;
        
        vector<int> freq(26,0);
        
        for (auto it:str)
        {
            freq[it-'a']++;
            
            if (freq[it-'a']>ceil(1.0*str.size()/2))
            {
                return "-1";
            }
        }
        
        
        for (int i=0; i<26; i++)
        {
            if (freq[i])
                pq.push({freq[i], 'a'+i});
        }
        
        while(pq.size()>1)
        {
            auto it1 = pq.top();
            int f1 = it1.first;
            char c1 = it1.second;
            pq.pop();
            
            auto it2 = pq.top();
            int f2 = it2.first;
            char c2 = it2.second;
            pq.pop();
            
            ans += c1;
            f1--;
            ans += c2;
            f2--;
            
            if (f1)
            pq.push({f1, c1});
            
            if (f2)
            pq.push({f2,c2});
            
        }

        if (!pq.empty())
        {
            ans += pq.top().second;
        }
        
        return ans;
        
        
        //code here
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
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends