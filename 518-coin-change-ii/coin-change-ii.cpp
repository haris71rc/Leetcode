class Solution {
private:
    int solve(int amount, vector<int>& coins, int i, int count, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(i==coins.size()) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];

        int lo=0;
        if(coins[i]<=amount){
            lo = count + solve(amount-coins[i], coins, i,count,dp);
        }
        int mtlo = solve(amount, coins, i+1, count, dp);

        return dp[i][amount] = lo+mtlo;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));

        return solve(amount,coins,0,0,dp);
    }
};