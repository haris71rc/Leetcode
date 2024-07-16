class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j,int n,int m,vector<vector<int>> &dp) {
        
        if (i == n-1 && j == m-1) return grid[i][j];
        
        if (i >= n || j >= m) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(grid, i, j+1,n,m,dp);
        int down = solve(grid, i+1, j,n,m,dp);
        
        return dp[i][j]=grid[i][j] + min(right, down);
    }
  
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0,n,m,dp);
    }
};