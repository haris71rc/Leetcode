class Solution {
private:
    int solve(vector<int>& arr, int k, int i, vector<int> &dp){
        if(i>arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0,ans=0;
        for(int j=i;j<min((int)arr.size(), i+k);j++){
            maxi=max(maxi,arr[j]);
            int len = j-i+1;

            int curr = maxi*len + solve(arr,k,j+1,dp);

            ans=max(ans,curr);
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return solve(arr,k,0,dp);
    }
};