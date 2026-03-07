class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minn = INT_MAX;
        int ans = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if (diff <= minn) {
                    minn = diff;
                    ans = sum;
                }
                if(sum < target) {
                    j++;
                }
               else if(sum > target) {
                    k--;
                } 
                else{
                    return ans;
                }
            }
        }
        return ans;
    }
};