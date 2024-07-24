class Solution {
private:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int minJump = nums.size()-1;
        for(int k = nums[i];k>=1;k--){
            int jump = 1+solve(nums,i+k,dp);
            minJump=min(jump,minJump);
        }
        return dp[i]=minJump;
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};