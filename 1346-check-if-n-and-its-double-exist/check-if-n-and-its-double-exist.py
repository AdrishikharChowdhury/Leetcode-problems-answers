class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        for i in range(len(arr)):
            for j in range(len(arr)):
                if i!=j and arr[i]==2*arr[j]:
                    return True
                j-=1
        return False