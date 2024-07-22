class Solution {
private:
    int solve(string s1, string s2, string s3,int i,int j,int k,vector<vector<vector<int>>> &dp){
        if(k==s3.length() && i==s1.length() && j==s2.length()){
            return 1;
        }
        if(k==s3.length()){
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int a=0,b=0;
        if(i<s1.length() && s1[i]==s3[k]){
             a= solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j<s2.length() && s2[j]==s3[k]){
            b= solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j][k]=a||b;
    }    
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};