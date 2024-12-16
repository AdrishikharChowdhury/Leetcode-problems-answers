class Solution(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        i=int(0)
        while(i<k):
            idx=self.minIdx(nums)
            nums[idx]*=multiplier
            i+=1
        return nums
    def minIdx(self,nums):
        min=int(nums[0])
        idx=0
        i=int(0)
        for i in range(len(nums)):
            if min>nums[i]:
                min=nums[i]
                idx=i
        return idx