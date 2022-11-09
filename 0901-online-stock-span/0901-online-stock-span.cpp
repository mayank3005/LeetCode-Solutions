class StockSpanner {
    stack<pair<int,int>> st;
    int res;
public:
    
    StockSpanner() {
        res=0;
    }
    
    int next(int price) {
       
        //Same as NGL nearest greater to left
        while(!st.empty() &&  st.top().first <= price)
            st.pop();
    
            
        int ngl = st.size() ? st.top().second : -1;
        st.push({price,res});
        res++;

        return res - ngl -1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */