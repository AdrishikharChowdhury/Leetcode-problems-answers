class Solution {
    public int maxArea(int[] heights) {
        int width,height,lp=0,rp=heights.length-1,mw=0,area=0;
        while(lp<rp)
        {
            width=rp-lp;
            height=Math.min(heights[lp],heights[rp]);
            area=width*height;
            mw=Math.max(mw,area);
            if(heights[lp]<heights[rp])
                lp+=1;
            else
                rp-=1;
        }
        return mw;
    }
}