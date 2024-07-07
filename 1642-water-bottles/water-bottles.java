class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int tb=numBottles,x,q,eb=numBottles;
        while(eb>=numExchange)
        {
            x=eb/numExchange;
            q=eb%numExchange;
            tb=tb+x;
            eb=x+q;
        }
        return tb;
    }
}