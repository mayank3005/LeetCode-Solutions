//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        set<string> st;
        for(auto i:wordList) st.insert(i);
        
        st.erase(startWord);
        queue<pair<string,int>> q;
        q.push({startWord,1});
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;q.pop();
            if(word==targetWord) return steps;
            string original = word;
            for(int i=0;i<original.size();i++){
                for(int j=0;j<26;j++){
                    char ch='a'+j;
                    word[i]=ch;
                    if(st.find(word)!=st.end()) q.push({word,steps+1}),st.erase(word);
                }
                word=original;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends