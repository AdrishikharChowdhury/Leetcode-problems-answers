class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        int i,j,count=0;
        for(i=2;i<n;i++)
        {
            if(isPrime[i])
            {
                count+=1;
                for(j=i*2;j<n;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        return count;
    }
};