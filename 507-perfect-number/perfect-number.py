class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num<=1:
            return False
        ans =1
        
        limit = int(num**0.5)+1
        for i in range(2,limit):
            if(num%i == 0):
                ans+=i
                if i!= num//i:
                    ans += num//i
        
        return num==ans