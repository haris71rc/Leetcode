class Solution {
private:
    int solve(vector<int>& prices, int i, int buy, int trans, vector<vector<vector<int>>> &dp){
        if(i>=prices.size()) return 0;
        if(trans==2) return 0;

        int ans=0;

        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];

        if(buy){
            int buy =- prices[i] + solve(prices,i+1,0,trans,dp);
            int skip= solve(prices,i+1,1,trans,dp);
            ans=max(buy,skip);
        }
        else{
            int sell =+ prices[i] + solve(prices,i+1,1,trans+1,dp);
            int skip= solve(prices,i+1,0,trans,dp);
            ans=max(sell,skip);
        }
        return dp[i][buy][trans] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,1,0,dp);
    }
};