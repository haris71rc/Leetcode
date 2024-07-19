class Solution {
private:
    
   int solve(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<long long int>> &dp) {
        if (i >= n || j >= m || grid[i][j] == 1) return 0;

        if (i == n - 1 && j == m - 1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=solve(grid, i, j + 1, n, m,dp) + solve(grid, i + 1, j, n, m,dp);
    }
  
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long long int>>dp(n,vector<long long int>(m,-1));

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0;

        return solve(obstacleGrid, 0, 0, n, m, dp);
    }
};
