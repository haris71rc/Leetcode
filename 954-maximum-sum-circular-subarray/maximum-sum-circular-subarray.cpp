class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxiSum=0,miniSum=0,totalSum=0,maxi=INT_MIN,mini=INT_MAX;

        for(int i=0;i<nums.size();i++){
            maxiSum = max(nums[i], nums[i]+maxiSum);
            maxi = max(maxiSum,maxi);

            miniSum = min(nums[i],nums[i]+miniSum);
            mini = min(mini,miniSum);

            totalSum+=nums[i];
        }

        int circularSum = totalSum-mini;

        if(circularSum==0) return maxi;

        return max(maxi,circularSum)
;    }
};