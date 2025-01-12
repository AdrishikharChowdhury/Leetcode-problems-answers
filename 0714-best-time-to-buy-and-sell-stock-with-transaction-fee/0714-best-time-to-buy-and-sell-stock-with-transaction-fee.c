int maxProfit(int* prices, int pricesSize, int fee) {
    if (pricesSize < 2) return 0;
    
    // hold[i] represents max profit on day i if we are holding stock
    // free[i] represents max profit on day i if we are not holding stock
    int hold = -prices[0];  // Buy first stock
    int free = 0;          // Don't buy anything
    
    for (int i = 1; i < pricesSize; i++) {
        // Either keep holding previous stock or buy new stock
        int prevHold = hold;
        hold = fmax(hold, free - prices[i]);
        
        // Either keep having no stock or sell current stock
        free = fmax(free, prevHold + prices[i] - fee);
    }
    
    // Final answer is maximum profit without holding any stock
    return free;
}