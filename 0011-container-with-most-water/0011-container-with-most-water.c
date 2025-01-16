int min(int a,int b)
{
    return a<b? a:b;
}
int max(int a,int b)
{
    return a>b? a:b;
}
int maxArea(int* heights, int heightsSize) {
    int width,height,lp=0,rp=heightsSize-1,mw=0,area=0;
    while(lp<rp)
    {
        width=rp-lp;
        height=min(heights[lp],heights[rp]);
        area=width*height;
        mw=max(mw,area);
        if(heights[lp]<heights[rp])
        {
            lp+=1;
        }
        else
        {
            rp-=1;
        }
    }
    return mw;
}