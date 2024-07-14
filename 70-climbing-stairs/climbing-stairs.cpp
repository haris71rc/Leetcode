class Solution {
private:
    int solve(int n){
        
        vector<int> dp(n+1,-1);
        int pp=1;
        int p=1;
        int curr;
        for(int i=2;i<=n;i++){
             curr = p + pp;
             pp=p;
             p=curr;
        }
        return p;
    }    
public:
    int climbStairs(int n) {
       return solve(n);
    }
};