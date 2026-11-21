class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        ans: list[list[int]] = []
        
        for i in range(0,numRows):
            inner = []
            for j in range(0,i+1):
                if j==0 or j==i:
                    inner.append(1)
                else:
                    sum = ans[i-1][j]+ans[i-1][j-1]
                    inner.append(sum)
            
            ans.append(inner)
        return ans
