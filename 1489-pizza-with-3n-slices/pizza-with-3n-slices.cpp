class Solution {
private:
    int solve(int index,vector<int>& slices,int n,int size){
        if(n==0 || index>=size)
           return 0;

        int include = slices[index] + solve(index+2,slices,n-1,size);
        int exclude = 0 + solve(index+1,slices,n,size);  
        return max(include,exclude); 
    }

    int solveMemo(int index,vector<int>& slices,int n,int size,vector<vector<int> > &dp){
        if(n==0 || index>=size)
           return 0;
        
        if(dp[index][n]!=-1)
           return dp[index][n];

        int include = slices[index] + solveMemo(index+2,slices,n-1,size,dp);
        int exclude = 0 + solveMemo(index+1,slices,n,size,dp);  
        return dp[index][n] = max(include,exclude); 
    }  

    int solveTab(vector<int>& slices){
        int k=slices.size();

/*****************************************************************************************/
        vector<vector<int> > dp1(k+2,vector<int> (k+2,0));

        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
        int include = slices[index] + dp1[index+2][n-1];
        int exclude = 0 + dp1[index+1][n];  
        dp1[index][n] = max(include,exclude);                 
            }
        }
        int includeFirst = dp1[0][k/3];

/*****************************************************************************************/
        vector<vector<int> > dp2(k+2,vector<int> (k+2,0));

        for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
        int include = slices[index] + dp2[index+2][n-1];
        int exclude = 0 + dp2[index+1][n];  
        dp2[index][n] = max(include,exclude);                 
            }
        }
        int excludeFirst = dp2[0][k/3]; 

        return max(excludeFirst,includeFirst);

    }      
public:
    int maxSizeSlices(vector<int>& slices) {
          int k = slices.size();

          vector<vector<int> > dp1(k,vector<int> (k,-1));
          int includeFirst=solveMemo(0,slices,k/3,k-1,dp1);

          vector<vector<int> > dp2(k,vector<int> (k,-1));
          int excludeFirst=solveMemo(1,slices,k/3,k,dp2);

          return max(includeFirst,excludeFirst);

       // return solveTab(slices);
    }
};