class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        ans=1
        binform=int(n)
        if n<0:
            x=1/x
            binform=-binform
        while binform>0:
            if binform%2==1:
                ans*=x
            x*=x
            binform/=2
        return ans