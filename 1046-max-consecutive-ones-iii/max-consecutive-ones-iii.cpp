class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        map<int, int> count;
        int i = 0, j = 0, maxFreq = 0, maxLen = 0;

        while (j < nums.size()) {
            count[nums[j]]++;
            while(count[0] > k) {
                count[nums[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};