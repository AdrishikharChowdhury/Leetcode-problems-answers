class Solution(object):
    def peakIndexInMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        st=1
        end=int(len(arr)-2)
        while st<=end:
            mid=int(st+(end-st)/2)
            if arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1]:
                return mid
            elif arr[mid-1]<arr[mid] :
                st=mid+1
            else :
                end=mid-1
        return -1