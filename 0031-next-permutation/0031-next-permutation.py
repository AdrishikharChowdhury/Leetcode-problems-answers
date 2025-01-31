
class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        piv = -1

        # Step 1: Find pivot
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                piv = i
                break

        # If no pivot is found, reverse the entire array
        if piv == -1:
            nums.reverse()
            return

        # Step 2: Find the smallest element greater than nums[piv]
        for i in range(n - 1, piv, -1):
            if nums[i] > nums[piv]:
                nums[i], nums[piv] = nums[piv], nums[i]
                break

        # Step 3: Reverse the suffix
        nums[piv + 1:] = reversed(nums[piv + 1:])