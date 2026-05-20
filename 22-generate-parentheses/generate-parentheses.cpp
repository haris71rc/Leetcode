class Solution {
private:
    void check(int n, vector<string> &ans, int open,int close, string curr){
        if(curr.length()>=2*n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            check(n,ans,open+1,close,curr+"(");
        }
        if(close<open){
            check(n,ans,open,close+1,curr+")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        check(n,ans,0,0,"");
        return ans;
    }
};