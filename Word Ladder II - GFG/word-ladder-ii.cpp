//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        vector<vector<string>> ans;
        
        unordered_set<string> st;
        for(auto i:wordList) st.insert(i);
        
        vector<string> curr={beginWord};
        queue<vector<string>> q;
        q.push(curr);
        
        vector<string> changed;
        changed.push_back(beginWord);
        
        int level=0;
        
        while(!q.empty()){
            vector<string> curr = q.front();q.pop();
            
            if(curr.size()>level){
                level++;
                for(auto &it:changed) st.erase(it);
                changed.clear();
            }
            
            string word=curr.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(curr);
                }else if(ans[0].size() == curr.size()){
                    ans.push_back(curr);
                }
            }
            string original = word;
            for(int i=0;i<original.size();i++){
                for(int j=0;j<26;j++){
                    char ch='a'+j;
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        curr.push_back(word);
                        changed.push_back(word);
                        q.push(curr);
                        curr.pop_back();
                    }
                }
                word=original;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends