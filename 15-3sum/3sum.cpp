class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> uniquePair;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum + nums[i] == 0) {
                    uniquePair.insert({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                } else if (sum + nums[i] < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        for(auto i: uniquePair){
            ans.push_back(i);
        }
        return ans;
    }
};