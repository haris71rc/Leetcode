class Solution {
private:
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>> &dp,int fee){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int ans=0;
        if(buy){
            int buy =- prices[i] + solve(prices,i+1,0,dp,fee);
            int skip = solve(prices,i+1,1,dp,fee);
            ans=max(buy,skip);
        }
        else{
            int sell =+ prices[i] + solve(prices,i+1,1,dp,fee)- fee;
            int skip = solve(prices,i+1,0,dp,fee);
            ans=max(sell,skip);
        }

        return dp[i][buy]=ans;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp,fee);
    }
};