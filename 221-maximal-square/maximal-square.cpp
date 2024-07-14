class Solution {
private:
    int solve(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>> &dp){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right = solve(matrix,i,j+1,maxi,dp);
        int down = solve(matrix,i+1,j,maxi,dp);
        int diagnal = solve(matrix,i+1,j+1,maxi,dp);
        if(matrix[i][j]=='1'){
            int ans = 1+min(right,min(down,diagnal));
            maxi=max(ans,maxi);
            return dp[i][j]=ans;
        }
        else{
            return 0;
        }
        
    } 

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n =matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(matrix,0,0,maxi,dp);
        return maxi*maxi;

    }
};