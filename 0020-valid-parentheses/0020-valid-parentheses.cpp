class Solution {
public:
    bool isClosed(char ch){
        return (ch==')' or ch==']' or ch=='}');
    }
    bool match(char i,char j){
        if(i=='(' and j==')') return true;
        if(i=='[' and j==']') return true;
        if(i=='{' and j=='}') return true;
        return false;
    }
    bool isValid(string s) {
        stack<int> st;
        for(auto i:s){
            if(isClosed(i)){
                if(st.empty()) return false;
                char ch=st.top();st.pop();
                if(!match(ch,i)) return false;
            }
            else st.push(i);
        }
        return st.empty();
    }
};