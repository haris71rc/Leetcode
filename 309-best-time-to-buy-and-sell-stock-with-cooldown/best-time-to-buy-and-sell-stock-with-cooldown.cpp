class Solution {
private:
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int ans1=0,ans2=0;
        if(buy){
            int buy =- prices[i] + solve(prices,i+1,0,dp);
            int skip = solve(prices,i+1,1,dp);
            ans1=max(buy,skip);
        }
        else{
            int sell =+ prices[i] + solve(prices,i+2,1,dp);
            int skip = solve(prices,i+1,0,dp);
            ans2=max(sell,skip);
        }

        return dp[i][buy]=max(ans1,ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};