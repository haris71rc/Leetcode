class Solution {
private:
    int solve(string w1, string w2, int i, int j, vector<vector<int>> &dp){
        if(i>=w1.length() || j>=w2.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int lo=0;
        if(w1[i] == w2[j]){
            lo= 1+solve(w1,w2,i+1,j+1, dp);
        }
        int mtlo = max(solve(w1,w2,i,j+1,dp), solve(w1,w2,i+1,j,dp));

        return dp[i][j] = max(lo,mtlo);
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int lcs = solve(word1,word2,0,0,dp);
        int l1= n-lcs;
        int l2= m-lcs;
        return l1+l2;
    }
};