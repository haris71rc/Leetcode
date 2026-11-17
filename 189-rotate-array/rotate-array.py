class Solution:

    def reverse(self,i,j,nums):
        while(i<j):
            nums[i],nums[j]=nums[j],nums[i]

            i+=1
            j-=1
        

    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k = k%n

        self.reverse(0,n-k-1,nums)
        self.reverse(n-k,n-1,nums)
        self.reverse(0,n-1,nums)


        