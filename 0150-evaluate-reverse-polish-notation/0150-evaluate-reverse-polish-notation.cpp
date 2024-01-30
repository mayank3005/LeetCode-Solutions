class Solution {
public:
    
    bool isOperator(string ch){
        return (ch=="/" or ch=="+" or ch=="*" or ch=="-");
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<long> st;
        
        for(auto i:tokens){
            if(isOperator(i)){
                
                long b=st.top();st.pop();
                long a=st.top();st.pop();
                long res;
                
                if(i[0]=='*') res=a*b;
                else if(i[0]=='/') res=a/b;
                else if(i[0]=='+') res=a+b;
                else res=a-b;
                
                st.push(res);
            }else{
                st.push(stoi(i));
            }
        }
        
        return st.top();
        
    }
};