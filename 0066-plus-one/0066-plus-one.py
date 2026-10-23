class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        num=0
        for digit in digits:
            num = num * 10 + digit
        num+=1
        newNum=[]
        while num>0:
            newNum.append(num%10)
            num//=10
        return newNum[::-1]