class Solution {
    public int maxProfit(int[] prices) {
        int mp=0,bb=prices[0],n=prices.length;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>bb)
            {
                mp=Math.max(mp,prices[i]-bb);
            }
            bb=Math.min(bb,prices[i]);
        }
        return mp;
    }
}