class Solution(object):
    def removeOccurrences(self, s, part):
        """
        :type s: str
        :type part: str
        :rtype: str
        """
        while part in s:
            s = s.replace(part, "", 1)  # Remove first occurrence of part
        return s