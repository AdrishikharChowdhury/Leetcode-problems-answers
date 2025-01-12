class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices.length < 2) return 0;
        
        // hold represents max profit if we are holding stock
        // free represents max profit if we are not holding stock
        int hold = -prices[0];  // Buy first stock
        int free = 0;          // Don't buy anything
        
        for (int i = 1; i < prices.length; i++) {
            // Either keep holding previous stock or buy new stock
            int prevHold = hold;
            hold = Math.max(hold, free - prices[i]);
            
            // Either keep having no stock or sell current stock
            free = Math.max(free, prevHold + prices[i] - fee);
        }
        
        // Final answer is maximum profit without holding any stock
        return free;
    }
}