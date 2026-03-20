class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMiniSum=0, currMaxiSum=0, maxi=INT_MIN, mini=INT_MAX, ans=INT_MIN;

        for(int i=0;i<nums.size();i++){
            currMaxiSum = max(nums[i], currMaxiSum+nums[i]);
            currMiniSum = min(nums[i], currMiniSum+nums[i]);

            mini = min(mini,currMiniSum);
            maxi = max(maxi,currMaxiSum);

            ans = max({ans,abs(mini),maxi});
        }
        return ans;
    }
};