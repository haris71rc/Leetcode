class Solution {
private:
    int solve(vector<int>& prices, int i, int buy, int trans, vector<vector<vector<int>>> &dp,int k){
        if(i>=prices.size()) return 0;
        if(trans==k) return 0;

        int ans=0;

        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];

        if(buy){
            int buy =- prices[i] + solve(prices,i+1,0,trans,dp,k);
            int skip= solve(prices,i+1,1,trans,dp,k);
            ans=max(buy,skip);
        }
        else{
            int sell =+ prices[i] + solve(prices,i+1,1,trans+1,dp,k);
            int skip= solve(prices,i+1,0,trans,dp,k);
            ans=max(sell,skip);
        }
        return dp[i][buy][trans] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(prices,0,1,0,dp,k);
    }
};