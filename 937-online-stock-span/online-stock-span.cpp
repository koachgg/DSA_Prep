class StockSpanner {
public:
    int i;
    stack<pair<int,int>>st;
   
    StockSpanner() {
        i =1;
        
    }
    
    int next(int price) 
    {
        
        int ans =0;
        while(!st.empty() and st.top().first<=price)
            st.pop();
        
        if(st.empty())
            ans = i;
        else
        {
            ans = i - st.top().second; 
        }
        
        st.push({price,i});
        i+=1;
        return ans;
       
    }
};