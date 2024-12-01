class Solution(object):
    def findFinalValue(self, nums, original):
        """
        :type nums: List[int]
        :type original: int
        :rtype: int
        """
        if original not in nums:
            return original
        else:
            return self.findFinalValue(nums,2*original)

        