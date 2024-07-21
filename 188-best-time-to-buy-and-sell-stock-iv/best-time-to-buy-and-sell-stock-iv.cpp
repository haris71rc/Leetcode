class Solution {
    private:
           int solveMemo(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[i][buy][limit]!=-1){
            return dp[i][buy][limit];
        }
        if(buy){
            int buyKro = -prices[i]+solveMemo(prices,i+1,0,limit,dp);
            int skipKro = 0+solveMemo(prices,i+1,1,limit,dp);
            dp[i][buy][limit] = max(buyKro,skipKro);
        }
        else{
            int sellKro = prices[i]+solveMemo(prices,i+1,1,limit-1,dp);
            int skipKro = 0+solveMemo(prices,i+1,0,limit,dp);
            dp[i][buy][limit] = max(sellKro,skipKro);
        }
        return dp[i][buy][limit];
    } 
public:
    int maxProfit(int k, vector<int>& prices) {
                int n=prices.size();

         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
         return solveMemo(prices,0,1,k,dp);
       
    }
};