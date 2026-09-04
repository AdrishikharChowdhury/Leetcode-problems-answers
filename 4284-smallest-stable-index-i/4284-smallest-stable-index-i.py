class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        for i in range(len(nums)):
            left_div=nums[:i+1]
            right_div=nums[i:]
            score=max(left_div)-min(right_div)
            if score<=k:
                return i
        return -1