class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int currentOne=0,maxiOne=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                currentOne=currentOne+1;
                maxiOne = Math.max(currentOne,maxiOne);
            }
            else{
                currentOne=0;
            }
        }
        return maxiOne;
    }
}