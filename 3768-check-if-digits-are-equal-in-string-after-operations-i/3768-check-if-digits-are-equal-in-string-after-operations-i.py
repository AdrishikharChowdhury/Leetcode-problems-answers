class Solution(object):
    def hasSameDigits(self, s):
        """
        :type s: str
        :rtype: bool
        """
        nums=[int(char) for char in s]
        while len(nums)>2:
            newNums=[]
            for i in range(len(nums)-1):
                newNums.append((nums[i] + nums[i+1]) % 10)
            nums=newNums
        
        return nums[0]==nums[1]