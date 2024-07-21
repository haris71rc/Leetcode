class Solution {
private:
    int solve(string words1, string words2,int i,int j,vector<vector<int>>& dp){
        if(i==-1 && j==-1) return 0;
        if(i==-1) return j+1;
        if(j==-1) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(words1[i]==words2[j]){
            return dp[i][j]=solve(words1,words2,i-1,j-1,dp);
        }
        else{
            int insert = 1+ solve(words1,words2,i-1,j-1,dp);
            int deletee = 1+ solve(words1,words2,i-1,j,dp);
            int replace = 1+ solve(words1,words2,i,j-1,dp);
            return dp[i][j]=min(insert,min(deletee,replace));
        }

    }
public:
    int minDistance(string word1, string word2){
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};