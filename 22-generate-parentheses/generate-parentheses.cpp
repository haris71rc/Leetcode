class Solution {
private:
    void solve(int n,vector<string> &ans,int open,int close,string curr){
        if(curr.length()==n*2){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            solve(n,ans,open+1,close,curr+"(");
        }
        if(close<open){
            solve(n,ans,open,close+1,curr+")");
        }
    }    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,ans,0,0,"");
        return ans;        
    }
};