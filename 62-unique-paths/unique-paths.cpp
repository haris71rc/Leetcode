class Solution {
private:
    int solve(int currRow,int currCol,int row,int col, vector<vector<int>> &dp){
        if(currRow>=row-1 && currCol>=col-1) return 1;

        if(dp[currRow][currCol]!=-1) return dp[currRow][currCol]; 

        int proceedRow=0,proceedCol=0;
        if(currRow<row-1)
         proceedRow = solve(currRow+1,currCol,row,col,dp);
        if(currCol<col-1)
         proceedCol = solve(currRow,currCol+1,row,col,dp);

        return dp[currRow][currCol] = proceedRow+proceedCol;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};