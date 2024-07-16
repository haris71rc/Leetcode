class Solution {
private:
    int solve(vector<vector<int>>& triangle,int n,int i,int j,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int iWala = triangle[i][j] + solve(triangle,n,i+1,j,dp);
        int iNextWala = triangle[i][j] + solve(triangle,n,i+1,j+1,dp);
        return dp[i][j]=min(iWala,iNextWala);
    }    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(triangle,n,0,0,dp);
    }
};