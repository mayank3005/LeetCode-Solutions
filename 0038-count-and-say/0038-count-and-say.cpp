class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        string temp="";
        for(int i=1;i<n;i++){
            string temp="";
            // cout<<s<<endl;
            int j=0;
            while(j<s.size()){
                int k=j;
                char ele=s[j];
                while(k<s.size() and s[k]==ele) k++;
                temp+=to_string(k-j);
                temp.push_back(ele);
                j=k;
            }
            s=temp;
        }
        return s;
    }
};