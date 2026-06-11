class Solution {
private:
    int solve(vector<int>& prices,int index,int buy, vector<vector<int>> &dp){
        if(index>=prices.size()) return 0;

        int ans1=0,ans2=0;

        if(dp[index][buy]!=-1) return dp[index][buy];

        if(buy){
            int buy =- prices[index] + solve(prices,index+1,0,dp);
            int skip = solve(prices,index+1,1,dp);
            ans1=max(buy,skip);
        }
        else{
            int sell =+ prices[index] + solve(prices,index+1,1,dp);
            int skip = solve(prices,index+1,0,dp);
            ans2=max(sell,skip);
        }
        return dp[index][buy]=max(ans1,ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};