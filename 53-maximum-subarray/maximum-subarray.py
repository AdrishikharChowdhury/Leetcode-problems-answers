class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        currentSum=0
        maxSum=-float('inf')
        for val in nums:
            currentSum+=val
            maxSum=max(currentSum,maxSum)
            if(currentSum<0):
                currentSum=0
        return maxSum