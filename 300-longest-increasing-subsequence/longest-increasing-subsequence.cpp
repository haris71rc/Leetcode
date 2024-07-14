class Solution {
    private:
           int solveMemo(int n,vector<int>& a,int curr,int prev,vector<vector<int>> &dp){
        //base case
        if(curr>=n)
          return 0;
          
        if(dp[curr][prev+1]!=-1) //we r doing prev+1, because minus one is not a valid index
           return dp[curr][prev+1];
        
        //include
        int include =0;
        if(prev==-1 || a[curr]>a[prev]){
            // prev=curr;
            include = 1+solveMemo(n,a,curr+1,curr,dp);
        }
        int exclude = 0+solveMemo(n,a,curr+1,prev,dp);
        
     return dp[curr][prev+1] = max(include,exclude);
      //because -1 is not a valid index
    }
        int solveTab(int n,vector<int>&a){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
         
         for(int curr=n-1;curr>=0;curr--){
             for(int prev=curr-1;prev>=-1;prev--){
             int include =0;
             if(prev==-1 || a[curr]>a[prev]){
            // prev=curr;
            include = 1+dp[curr+1][curr+1]; 
        }
        int exclude = 0+dp[curr+1][prev+1];
                    dp[curr][prev+1] = max(include,exclude); 

             }
         }
         return dp[0][0];
    }
        int spaceOptimization(int n,vector<int> &a){
         
         vector<int>currRow(n+1,0);
         vector<int>nextRow(n+1,0);
        
        
       for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
             int include =0;
             if(prev==-1 || a[curr]>a[prev]){
            // prev=curr;
            include = 1+nextRow[curr+1];
        }
               int exclude = 0+nextRow[prev+1];
               currRow[prev+1] = max(include,exclude); 
               
             }
                          nextRow=currRow;
         }
         return currRow[0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1)); //curr jaa rha 0 se n-1 tk & prev ja rha -1 se n-1 tk
        // return solveMemo(n,nums,0,-1,dp);
        return spaceOptimization(n,nums);
    }
};