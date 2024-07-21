class Solution {
private:
    int solve(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>> &dp){
        if(i>=prices.size()) return 0;
        if(limit==0) return 0;

        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];

        if(buy){
            int buyKro = -prices[i] + solve(prices,i+1,0,limit,dp);
            int skipKro = 0 + solve(prices,i+1,buy,limit,dp);
            dp[i][buy][limit] =  max(buyKro,skipKro);
        }
        else{
            int sellKro = prices[i]+solve(prices,i+1,1,limit-1,dp);
            int skipKro = 0 + solve(prices,i+1,buy,limit,dp);
            dp[i][buy][limit] = max(sellKro,skipKro);
        }
        return dp[i][buy][limit];
    }    
public:
    int maxProfit(vector<int>& prices) {
        int buy=1;
        int limit=2;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,buy,limit,dp);
    }
};