class Solution:
    def isAlphaNum(self, ch):
        return ch.isalnum()

    def isPalindrome(self, s):
        st, end = 0, len(s) - 1
        
        while st < end:
            while st < end and not self.isAlphaNum(s[st]):
                st += 1
            while st < end and not self.isAlphaNum(s[end]):
                end -= 1
            if s[st].lower() != s[end].lower():
                return False
            st += 1
            end -= 1
        
        return True