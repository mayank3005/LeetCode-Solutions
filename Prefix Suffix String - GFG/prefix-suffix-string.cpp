//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    class Node{
        public:
        Node *arr[26];
        bool isEnd;
        Node(){
            for(int i=0;i<26;i++) arr[i]=NULL;
            isEnd=false;
        }
        Node *get(char ch){
            return arr[ch-'a'];
        }
        void set(char ch){
            arr[ch-'a']=new Node();
        }
        void setEnd(){isEnd=true;}
        bool getEnd(){return isEnd;}
    };
    class Trie{
        public:
        Node *root,*root2;
        Trie(){root=new Node();root2=new Node();}
        void insert(string &s,bool isRev=false){
            Node *temp=root;
            if(isRev) temp=root2;
            for(auto &i:s){
                if(!temp->get(i)) temp->set(i);
                temp=temp->get(i);
            }
            temp->setEnd();
        }
        bool check(string &s,bool isRev=false){
            Node *temp=root;
            if(isRev) temp=root2;
            for(auto i:s){
                if(!temp->get(i)) return false;
                temp=temp->get(i);
            }
            return true;
        }
    };
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Trie trie;
        for(auto i:s1){
            trie.insert(i);
            reverse(i.begin(),i.end());
            trie.insert(i,true);
        }
        int ans=0;
        for(auto i:s2){
            string str=i;reverse(str.begin(),str.end());
            ans+=(trie.check(i) or trie.check(str,true));
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends