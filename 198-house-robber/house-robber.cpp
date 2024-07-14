class Solution {
private:
    int solve(vector<int>& nums,int n,int i,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int inc = solve(nums,n,i+2,dp) + nums[i];
        int exl = solve(nums,n,i+1,dp) + 0;
        return dp[i] = max(inc,exl);
    } 
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,n,0,dp);
    }
};