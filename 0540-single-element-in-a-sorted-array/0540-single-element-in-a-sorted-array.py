class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        st=0
        end=int(len(nums)-1)
        n=int(len(nums))
        if n==1:
            return nums[0]
        while st<=end:
            mid=int(st+(end-st)/2)
            if mid==0 and nums[0]!=nums[1]:
                return nums[mid]
            if mid==n-1 and nums[n-1]!=nums[n-2]:
                return nums[mid]
            if nums[mid-1]!=nums[mid] and nums[mid]!=nums[mid+1]:
                return nums[mid]
            if mid%2==0:
                if nums[mid-1]==nums[mid]:
                    end=mid-1
                else:
                    st=mid+1
            else:
                if nums[mid-1]==nums[mid]:
                    st=mid+1
                else:
                    end=mid-1
        return -1