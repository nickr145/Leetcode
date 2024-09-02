class StockSpanner {
private:
    // This stack stores pairs of (price, span)
    stack<pair<int, int>> stockStack;
    
public:
    StockSpanner(){}
    
    int next(int price) {
        
        // Span for the current price starts off as 1
        int span = 1;  
        
        // Pop the stack while the current price is greater than or equal to the top of the stack
        while (!stockStack.empty() && stockStack.top().first <= price) {

            // Accumulate the span from the popped prices
            span += stockStack.top().second;  

            // Remove the smaller/equal price from the stack
            stockStack.pop();
        }
        
        // Push the current price and its span onto the stack
        stockStack.push({price, span});
        
        // Return the computed span for the current price
        return span;  
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
