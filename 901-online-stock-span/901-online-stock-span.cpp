class StockSpanner {
    stack<pair<int,int>>st;
    
    
public:

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if(st.empty() && price!=NULL)
        {
            st.push({price,1});
            return 1;
        }
        else
        {
            if(st.top().first>price)
            {
                st.push({price,1});
                return 1;
            }
            int sum=0;
            while(!st.empty() && st.top().first<=price)
            {
                sum+=st.top().second;
                st.pop();
            }
            st.push({price,sum+1});
            return sum+1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */