class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        mid=0
        st=0
        end=len(nums)-1
        while st<=end:
            mid=st+(end-st)/2
            if nums[mid]==target:
                return mid
            if nums[st]<=nums[mid]:
                if nums[st]<=target and target<=nums[mid]:
                    end=mid-1
                else:
                    st=mid+1
            else:
                if nums[mid]<=target and target<=nums[end]:
                    st=mid+1
                else:
                    end=mid-1
        return -1