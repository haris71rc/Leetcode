class Solution {
private:
    int solve(vector<int>& nums,int prev,int curr,vector<vector<int>>& dp){
        if(curr>=nums.size()) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];

        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
             include=1+solve(nums,curr,curr+1,dp);
        }
        int exclude =  solve(nums,prev,curr+1,dp);

        return dp[prev+1][curr]=max(include,exclude);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,-1,0,dp);
    }
};