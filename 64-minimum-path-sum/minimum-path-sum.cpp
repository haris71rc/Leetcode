class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j,int n,int m,vector<vector<int>> &dp) {
        
        if (i == n-1 && j == m-1) return grid[i][j];
        
        if (i >= n || j >= m) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = grid[i][j] + solve(grid, i, j+1,n,m,dp);
        int down = grid[i][j] + solve(grid, i+1, j,n,m,dp);
        
        return dp[i][j]= min(right, down);
    }
    int solveMemo(vector<vector<int>>& grid,int n,int m){
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[n-1][m-1]=grid[n-1][m-1];
        for (int j = m-2; j >= 0; --j) {
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        }
        
        // Fill the last column (can only move down)
        for (int i = n-2; i >= 0; --i) {
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        }
        for(int i=n-2;i>=0;--i){
            for(int j=m-2;j>=0;--j){
                int right = dp[i][j+1];
                int down = dp[i+1][j];
        
                dp[i][j]=grid[i][j] + min(right, down);
            }
        }
        return dp[0][0];
    }
  
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveMemo(grid,n,m);
    }
};