int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int maxProfit(int* prices, int pricesSize) {
    int i,maxProfit,bestBuy=prices[0];
    for(i=1;i<pricesSize;i++)
    {
        if(prices[i]>bestBuy)
        {
            maxProfit=max(maxProfit,prices[i]-bestBuy);
        }
        bestBuy=min(bestBuy,prices[i]);
    }
    return maxProfit;
}