class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n=int(len(prices))
        mp=0
        bb=prices[0]
        i=1
        for i in range(n):
            if prices[i]>bb:
                mp=max(mp,prices[i]-bb)
            bb=min(bb,prices[i])
        return mp