class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        n=int(len(s))
        for i in range(n/2) :
            temp=s[i]
            s[i]=s[n-i-1]
            s[n-i-1]=temp