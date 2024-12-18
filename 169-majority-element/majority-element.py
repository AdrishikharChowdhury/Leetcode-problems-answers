class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        freq=0
        ans=0
        numsSize=len(nums)
        for i in range(len(nums)):
            if freq==0:
                ans=nums[i]
            if ans==nums[i]:
                freq+=1
            else:
                freq-=1
        c=0
        for val in nums:
            if val==ans:
                c+=1
        if c>numsSize/2:
            return ans
        else:
            return -1
        