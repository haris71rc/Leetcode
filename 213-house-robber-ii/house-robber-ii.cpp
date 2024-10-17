class Solution {
private:
    int solve(vector<int>& valueInHouse, int i, int size, vector<int>& dp) {
        if (i >= size)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int include = valueInHouse[i] + solve(valueInHouse, i + 2, size, dp);
        int exclude = 0 + solve(valueInHouse, i + 1, size, dp);

        return dp[i] = max(include, exclude);
    }

public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        vector<int> dp(size, -1);
        int robFirst = solve(nums, 0, size - 1, dp);
        fill(dp.begin(),dp.end(),-1);
        int robSecond = solve(nums, 1, size, dp);

        return max(robFirst, robSecond);
    }
};