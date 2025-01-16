class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int width,height,lp=0,rp=heights.size()-1,mw=0,area=0;
        while(lp<rp)
        {
            width=rp-lp;
            height=min(heights[lp],heights[rp]);
            area=width*height;
            mw=max(mw,area);
            heights[lp]<heights[rp]?lp+=1:rp-=1;
        }
        return mw;
    }
};