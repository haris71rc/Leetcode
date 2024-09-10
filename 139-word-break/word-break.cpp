class Solution {
private:
    bool solve(string s, vector<string>& wordDict,int ans,vector<int>& dp){
        if(ans==s.size()) return true;

        if(dp[ans]!=-1) return dp[ans];
        for(int i=0;i<wordDict.size();i++){
            string word = wordDict[i];

            if(s.substr(ans,word.size()) == word){
                if(solve(s,wordDict,ans+word.size(),dp)){
                    return dp[ans]=true;
                }
            }
        }
        return dp[ans]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return solve(s,wordDict,0,dp);
    }
};