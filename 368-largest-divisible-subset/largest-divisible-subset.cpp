class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> parent(n);

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int maxLen=1,lastIndex=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                lastIndex=i;
            }
        }

        vector<int> ans;

        while(parent[lastIndex] != lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex=parent[lastIndex];
        }
        ans.push_back(nums[lastIndex]);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};