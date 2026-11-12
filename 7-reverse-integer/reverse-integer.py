class Solution:
    def reverse(self, x: int) -> int:
        reversedNum=0
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        num=x
        limit = 7 if x >= 0 else 8
        if x<0:
            num=-x
        while(num>0):
            rem = num%10
            if reversedNum > INT_MAX // 10:
                return 0

            if reversedNum == INT_MAX // 10 and rem > limit:
                return 0
            reversedNum= reversedNum*10 + rem
            num= int(num/10)

        return (-1*reversedNum) if x<0 else reversedNum
        
        
        