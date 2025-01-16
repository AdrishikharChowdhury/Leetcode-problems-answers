class Solution(object):
    def maxArea(self, heights):
        """
        :type height: List[int]
        :rtype: int
        """
        lp=0
        rp=int(len(heights)-1)
        mw=0
        height=0
        width=0
        while lp<rp:
            width=int(rp-lp)
            height=min(heights[lp],heights[rp])
            area=int(width*height)
            mw=max(mw,area)
            if heights[lp]<heights[rp]:
                lp+=1
            else:
                rp-=1
        return mw
        